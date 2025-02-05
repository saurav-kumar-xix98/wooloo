#include <library/LC3352_CountKReducibleNumbersLessThanN.hpp>
#include <vector>

namespace LC3352 {
    constexpr int modulo = 1'000'000'007;

    long long nCr(int n, int r) {
        if (n < 0 || r < 0 || n < r)
            return 0;

        if (r > n - r)
            r = n - r;

        static std::vector<std::vector<int>> lookupTable = {{1}};

        for (int i = lookupTable.size(); i <= n; ++i) {
            lookupTable.push_back({});
            lookupTable[i].push_back(1);
            for (int j = 1; j <= i / 2; ++j)  {
                long long val = (nCr(i - 1, j - 1) + nCr(i - 1, j)) % modulo;
                lookupTable[i].push_back(val);
            }
        }

        return lookupTable[n][r];
    }

    long long countSmallerNumbers(int n, const std::string upperLimit) {
        long long count = 0;

        int bitCount = n;
        for (int i = 0; i < upperLimit.size(); ++i) {
            if (upperLimit[i] == '0')
                continue;
            count = (count + nCr(upperLimit.size() - i - 1, bitCount)) % modulo;
            bitCount--;
        }

        return count;
    }

    int countBits(int num) {
        if (num == 0)
            return 0;
        return (num & 1) + countBits(num >> 1);
    }
}

int LC3352::countKReducibleNumbers(std::string s, int k) {
    std::vector<int> kLookupMap(s.size() + 1);
    kLookupMap[0] = -1;
    kLookupMap[1] = 0;
    for(int i = 2; i < kLookupMap.size(); ++i) {
        int bitCount = countBits(i);
        kLookupMap[i] = kLookupMap[bitCount] + 1;
    }

    long long ans = 0;
    for (int i = 1; i < kLookupMap.size(); ++i) {
        if (kLookupMap[i] < k) {
            ans = (ans + countSmallerNumbers(i, s)) % modulo;
        }
    }

    return ans;
}
