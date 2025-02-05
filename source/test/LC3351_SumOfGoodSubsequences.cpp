#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC3351_SumOfGoodSubsequences.hpp>

void testLC3351(const std::string &input, int output) {
    auto vec = Util::Parser::parse<std::vector<int>>(input);
    const auto result = LC3351::sumOfGoodSubsequences(vec);
    ASSERT_EQ(output, result);
}

TEST(LC3351_SumOfGoodSubsequences, TEST_1) {
    const std::string input = "[1,2,1]";
    const int output = 14;

    testLC3351(input, output);
}

TEST(LC3351_SumOfGoodSubsequences, TEST_2) {
    const std::string input = "[3,4,5]";
    const int output = 40;

    testLC3351(input, output);
}
