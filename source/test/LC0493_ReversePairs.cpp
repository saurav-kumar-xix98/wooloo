#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC0493_ReversePairs.hpp>

void testLC0493(const std::string &input, const int output) {
    auto nums = Util::Parser::parse<std::vector<int>>(input);

    const auto result = LC0493::reversePairs(nums);
    ASSERT_EQ(output, result);
}

TEST(LC0493_ReversePairs, TEST_1) {
    const std::string input = "[1,3,2,3,1]";
    const int output = 2;

    testLC0493(input, output);
}

TEST(LC0493_ReversePairs, TEST_2) {
    const std::string input = "[2,4,3,5,1]";
    const int output = 3;

    testLC0493(input, output);
}
