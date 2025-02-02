#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC2440_CreateComponentsWithSameValue.hpp>

void testLC2440(const std::string &input1, const std::string &input2, const int output) {
    auto nums = Util::Parser::parse<std::vector<int>>(input1);
    auto edges = Util::Parser::parse<std::vector<std::vector<int>>>(input2);
    const auto result = LC2440::componentValue(nums, edges);
    ASSERT_EQ(output, result);
}

TEST(LC2440_CreateComponentsWithSameValue, TEST_1) {
    const std::string nums = "[6,2,2,2,6]";
    const std::string edges = "[[0,1],[1,2],[1,3],[3,4]]";
    const int output = 2;

    testLC2440(nums, edges, output);
}

TEST(LC2440_CreateComponentsWithSameValue, TEST_2) {
    const std::string nums = "[2]";
    const std::string edges = "[]";
    const int output = 0;

    testLC2440(nums, edges, output);
}
