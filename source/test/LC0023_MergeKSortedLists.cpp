#include <gtest/gtest.h>
#include <library/LC0023_MergeKSortedLists.hpp>
#include <util/Parser.hpp>
#include <util/ListNode.hpp>

void testLC0023(const std::string &input, const std::string &output) {
    auto lists = Util::Parser::parse<std::vector<Datatype::ListNode*>>(input);
    const auto expected = Util::Parser::parse<Datatype::ListNode*>(output);

    const auto result = LC0023::mergeKLists(lists);
    Util::ListNode::assertListNodeEq(expected, result);
    Util::ListNode::deleteList(expected);
    Util::ListNode::deleteList(result);
}

TEST(LC0023_MergeKSortedLists, TEST_1) {
    const std::string input = "[[1,4,5],[1,3,4],[2,6]]";
    const std::string output = "[1,1,2,3,4,4,5,6]";

    testLC0023(input, output);
}


TEST(LC0023_MergeKSortedLists, TEST_2) {
    const std::string input = "[]";
    const std::string output = "[]";

    testLC0023(input, output);
}

TEST(LC0023_MergeKSortedLists, TEST_3) {
    const std::string input = "[[]]";
    const std::string output = "[]";

    testLC0023(input, output);
}
