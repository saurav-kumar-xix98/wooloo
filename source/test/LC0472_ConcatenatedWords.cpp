#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC0472_ConcatenatedWords.hpp>
#include <unordered_set>

void testLC0472(const std::string &input, const std::string output) {
    auto words = Util::Parser::parse<std::vector<std::string>>(input);
    const auto expected = Util::Parser::parse<std::vector<std::string>>(output);

    const std::vector<std::string> result = LC0472::findAllConcatenatedWordsInADict(words);
    ASSERT_EQ(expected.size(), result.size());
    std::unordered_set<std::string> expectedSet(expected.begin(), expected.end());
    std::unordered_set<std::string> resultSet(result.begin(), result.end());
    ASSERT_EQ(expectedSet, resultSet);
}

TEST(LC0472_ConcatenatedWords, TEST_1) {
    const std::string input = "[cat,cats,catsdogcats,dog,dogcatsdog,hippopotamuses,rat,ratcatdogcat]";
    const std::string output = "[catsdogcats,dogcatsdog,ratcatdogcat]";

    testLC0472(input, output);
}

TEST(LC0472_ConcatenatedWords, TEST_2) {
    const std::string input = "[cat,dog,catdog]";
    const std::string output = "[catdog]";

    testLC0472(input, output);
}
