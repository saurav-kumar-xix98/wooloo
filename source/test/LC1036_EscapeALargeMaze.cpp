#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC1036_EscapeALargeMaze.hpp>

void testLC1036(const std::string &input1, const std::string &input2, const std::string &input3, const int output) {
    auto blocked = Util::Parser::parse<std::vector<std::vector<int>>>(input1);
    auto source = Util::Parser::parse<std::vector<int>>(input2);
    auto target = Util::Parser::parse<std::vector<int>>(input3);
    const auto result = LC1036::isEscapePossible(blocked, source, target);
    ASSERT_EQ(output, result);
}

TEST(LC1036_EscapeALargeMaze, TEST_1) {
    const std::string blocked = "[[0,1],[1,0]]";
    const std::string source = "[0,0]";
    const std::string target = "[0,2]";
    const bool output = false;

    testLC1036(blocked, source, target, output);
}

TEST(LC1036_EscapeALargeMaze, TEST_2) {
    const std::string blocked = "[]";
    const std::string source = "[0,0]";
    const std::string target = "[999999,999999]";
    const bool output = true;

    testLC1036(blocked, source, target, output);
}
