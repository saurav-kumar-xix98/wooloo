#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC2458_HeightOfBinaryTreeAfterSubtreeRemovalQueries.hpp>
#include <util/TreeNode.hpp>
#include <vector>
#include <unordered_set>
#include <string>

void testLC2458(const std::string &input1, const std::string &input2, const std::string output) {
    auto root = Util::Parser::parse<Datatype::TreeNode*>(input1);
    auto queries = Util::Parser::parse<std::vector<int>>(input2);
    auto expected = Util::Parser::parse<std::vector<int>>(output);

    const auto result = LC2458::treeQueries(root, queries);
    ASSERT_EQ(expected.size(), result.size());
    std::unordered_set<int> expectedSet(expected.begin(), expected.end());
    std::unordered_set<int> resultSet(result.begin(), result.end());
    ASSERT_EQ(expectedSet, resultSet);
    Util::TreeNode::deleteTree(root);
}

TEST(LC2458_HeightOfBinaryTreeAfterSubtreeRemovalQueries, TEST_1) {
    const std::string tree = "[1,3,4,2,null,6,5,null,null,null,null,null,7]";
    const std::string queries = "[4]";
    const std::string output = "[2]";

    testLC2458(tree, queries, output);
}

TEST(LC2458_HeightOfBinaryTreeAfterSubtreeRemovalQueries, TEST_2) {
    const std::string tree = "[5,8,9,2,1,3,7,4,6]";
    const std::string queries = "[3,2,4,8]";
    const std::string output = "[3,2,3,2]";

    testLC2458(tree, queries, output);
}
