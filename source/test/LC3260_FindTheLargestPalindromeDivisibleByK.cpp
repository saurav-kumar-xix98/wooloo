#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC3260_FindTheLargestPalindromeDivisibleByK.hpp>

void testLC3260(const int n, int k, const std::string &output) {
    const auto result = LC3260::largestPalindrome(n, k);
    ASSERT_EQ(output, result);
}

TEST(LC3260_FindTheLargestPalindromeDivisibleByK, TEST_1) {
    const int n = 3;
    const int k = 5;
    const std::string output = "595";

    testLC3260(n, k, output);
}

TEST(LC3260_FindTheLargestPalindromeDivisibleByK, TEST_2) {
    const int n = 1;
    const int k = 4;
    const std::string output = "8";

    testLC3260(n, k, output);
}

TEST(LC3260_FindTheLargestPalindromeDivisibleByK, TEST_3) {
    const int n = 5;
    const int k = 6;
    const std::string output = "89898";

    testLC3260(n, k, output);
}
