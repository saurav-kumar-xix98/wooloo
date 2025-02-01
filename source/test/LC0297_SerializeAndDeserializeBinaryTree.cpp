#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC0297_SerializeAndDeserializeBinaryTree.hpp>
#include <util/TreeNode.hpp>

void testLC0297(const std::string &input, const std::string output) {
    const auto inputTree = Util::Parser::parse<Datatype::TreeNode*>(input);
    const auto outputTree = Util::Parser::parse<Datatype::TreeNode*>(output);

    const auto serealized = LC0297::serialize(inputTree);
    const auto deserealized = LC0297::deserialize(serealized);
    Util::TreeNode::assertTreeNodeEq(outputTree, deserealized);
    Util::TreeNode::deleteTree(inputTree);
    Util::TreeNode::deleteTree(outputTree);
    Util::TreeNode::deleteTree(deserealized);
}

TEST(LC0297_SerializeAndDeserializeBinaryTree, TEST_1) {
    const std::string input = "[1,2,3,null,null,4,5]";
    const std::string output = "[1,2,3,null,null,4,5]";

    testLC0297(input, output);
}

TEST(LC0297_SerializeAndDeserializeBinaryTree, TEST_2) {
    const std::string input = "[]";
    const std::string output = "[]";

    testLC0297(input, output);
}
