#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC2872_MaximumNumberOfKDivisibleComponents.hpp>

void testLC2872(const int n, const std::string &input1, const std::string &input2, const int k, const int output) {
    auto edges = Util::Parser::parse<std::vector<std::vector<int>>>(input1);
    auto values = Util::Parser::parse<std::vector<int>>(input2);
    const auto result = LC2872::maxKDivisibleComponents(n, edges, values, k);
    ASSERT_EQ(output, result);
}

TEST(LC2872_MaximumNumberOfKDivisibleComponents, TEST_1) {
    const int n = 5;
    const std::string edges = "[[0,2],[1,2],[1,3],[2,4]]";
    const std::string values = "[1,8,1,4,4]";
    const int k = 6;
    const int output = 2;

    testLC2872(n, edges, values, k, output);
}

TEST(LC2872_MaximumNumberOfKDivisibleComponents, TEST_2) {
    const int n = 7;
    const std::string edges = "[[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]]";
    const std::string values = "[3,0,6,1,5,2,1]";
    const int k = 3;
    const int output = 3;

    testLC2872(n, edges, values, k, output);
}
