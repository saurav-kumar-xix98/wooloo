#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC3108_MinimumCostWalkInWeightedGraph.hpp>

void testLC3108(const int n, const std::string &input1, const std::string &input2, const std::string &output) {
    auto edges = Util::Parser::parse<std::vector<std::vector<int>>>(input1);
    auto queries = Util::Parser::parse<std::vector<std::vector<int>>>(input2);
    auto expected = Util::Parser::parse<std::vector<int>>(output);
    const auto result = LC3108::minimumCost(n, edges, queries);
    ASSERT_EQ(expected, result);
}

TEST(LC3108_MinimumCostWalkInWeightedGraph, TEST_1) {
    const int n = 5;
    const std::string edges = "[[0,1,7],[1,3,7],[1,2,1]]";
    const std::string queries = "[[0,3],[3,4]]";
    const std::string output = "[1,-1]";

    testLC3108(n, edges, queries, output);
}

TEST(LC3108_MinimumCostWalkInWeightedGraph, TEST_2) {
    const int n = 3;
    const std::string edges = "[[0,2,7],[0,1,15],[1,2,6],[1,2,1]]";
    const std::string queries = "[[1,2]]";
    const std::string output = "[0]";

    testLC3108(n, edges, queries, output);
}
