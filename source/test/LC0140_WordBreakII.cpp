#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC0140_WordBreakII.hpp>
#include <unordered_set>

void testLC0140(const std::string &str, const std::string &input2, const std::string output) {
    auto wordDict = Util::Parser::parse<std::vector<std::string>>(input2);
    const auto expected = Util::Parser::parse<std::vector<std::string>>(output);

    const std::vector<std::string> result = LC0140::wordBreak(str, wordDict);
    ASSERT_EQ(expected.size(), result.size());
    std::unordered_set<std::string> expectedSet(expected.begin(), expected.end());
    std::unordered_set<std::string> resultSet(result.begin(), result.end());
    ASSERT_EQ(expectedSet, resultSet);
}

TEST(LC0140_WordBreakII, TEST_1) {
    const std::string input1 = "catsanddog";
    const std::string input2 = "[cat,cats,and,sand,dog]";
    const std::string output = "[cats and dog,cat sand dog]";

    testLC0140(input1, input2, output);
}

TEST(LC0140_WordBreakII, TEST_2) {
    const std::string input1 = "pineapplepenapple";
    const std::string input2 = "[apple,pen,applepen,pine,pineapple]";
    const std::string output = "[pine apple pen apple,pineapple pen apple,pine applepen apple]";

    testLC0140(input1, input2, output);
}

TEST(LC0140_WordBreakII, TEST_3) {
    const std::string input1 = "catsandog";
    const std::string input2 = "[cats,dog,sand,and,cat]";
    const std::string output = "[]";

    testLC0140(input1, input2, output);
}
