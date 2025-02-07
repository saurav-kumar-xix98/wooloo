#include <library/LC1808_MaximizeNumberOfNiceDivisors.hpp>

namespace LC1808 {
    long long mod(long long x) {
        return x % 1'000'000'007;
    }

    long long power(long long x, long long y) {
        long long ans = 1;
        while (y != 0) {
            if (y & 1)
                ans = mod(ans * x);
            x = mod(x * x);
            y /= 2;
        }
        return ans;
    }
}

int LC1808::maxNiceDivisors(int primeFactors) {
    if (primeFactors <= 4)
        return primeFactors;

    if (primeFactors % 3 == 1)
        return mod(power(3, primeFactors / 3 - 1) * 4);

    if (primeFactors % 3 == 2)
        return mod(power(3, primeFactors / 3) * 2);

    return power(3, primeFactors / 3);
}
