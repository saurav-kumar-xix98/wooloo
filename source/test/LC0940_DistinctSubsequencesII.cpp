#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC0940_DistinctSubsequencesII.hpp>

void testLC0940(const std::string &input, const int output) {
    const auto result = LC0940::distinctSubseqII(input);
    ASSERT_EQ(output, result);
}

TEST(LC0940_DistinctSubsequencesII, TEST_1) {
    const std::string input = "abc";
    const int output = 7;

    testLC0940(input, output);
}

TEST(LC0940_DistinctSubsequencesII, TEST_2) {
    const std::string input = "aba";
    const int output = 6;

    testLC0940(input, output);
}

TEST(LC0940_DistinctSubsequencesII, TEST_3) {
    const std::string input = "aaa";
    const int output = 3;

    testLC0940(input, output);
}
