#include <library/LC3351_SumOfGoodSubsequences.hpp>
#include <unordered_map>

int LC3351::sumOfGoodSubsequences(std::vector<int> &nums) {
    std::unordered_map<int, std::pair<long long, long long>> lookupMap;

    const long long modulo = 1'000'000'007;

    for (int num : nums) {
        const auto [countN, sumN] = lookupMap[num];
        const auto [countNMinusOne, sumNMinusOne] = lookupMap[num - 1];
        const auto [countNPlusOne, sumNPlusOne] = lookupMap[num + 1];

        long long newCount = (countN + countNMinusOne + countNPlusOne + 1) % modulo;
        long long newSum = (sumN + sumNMinusOne + sumNPlusOne + num) % modulo + ((countNMinusOne + countNPlusOne) * num) % modulo;
        if (newSum < 0)
            newSum = ((newSum % modulo) + modulo) % modulo;

        lookupMap[num] = {newCount, newSum};
    }

    long long ans = 0;
    for (auto [num, countSumPair] : lookupMap) {
        auto [count, sum] = countSumPair;
        ans = (ans + sum) % modulo;
    }

    return ans;
}
