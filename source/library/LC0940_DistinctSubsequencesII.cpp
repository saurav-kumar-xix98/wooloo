#include <library/LC0940_DistinctSubsequencesII.hpp>

#include <vector>
#include <array>

int LC0940::distinctSubseqII(std::string s) {
    const int modulo_constant = 1'000'000'007;
    std::vector<long long> count1(s.size(), 0);
    std::vector<long long> count2(s.size(), 0);
    std::array<int, 26> lastIndex;
    lastIndex.fill(-1);

    count1[0] = 1;
    count2[0] = 1;
    lastIndex[s[0] - 'a'] = 0;

    for (int i = 1; i < s.size(); ++i) {
        int charIndex = s[i] - 'a';
        count1[i] = (count1[i - 1] + count2[i - 1]) % modulo_constant;
        count2[i] = (count1[i - 1] + count2[i - 1]) % modulo_constant;
        if (lastIndex[charIndex] != -1) {
            count2[i] = (count2[i] - count1[lastIndex[charIndex]] + modulo_constant) % modulo_constant;
        }
        lastIndex[charIndex] = i;
    }
    return (count1.back() + count2.back() - 1) % modulo_constant;
}
