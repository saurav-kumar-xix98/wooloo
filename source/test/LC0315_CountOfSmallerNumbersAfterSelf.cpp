#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC0315_CountOfSmallerNumbersAfterSelf.hpp>

void testLC0315(const std::string &input, const std::string output) {
    auto nums = Util::Parser::parse<std::vector<int>>(input);
    const auto expectedCounts = Util::Parser::parse<std::vector<int>>(output);

    const auto counts = LC0315::countSmaller(nums);
    ASSERT_EQ(expectedCounts, counts);
}

TEST(LC0315_CountOfSmallerNumbersAfterSelf, TEST_1) {
    const std::string input = "[5,2,6,1]";
    const std::string output = "[2,1,1,0]";

    testLC0315(input, output);
}

TEST(LC0315_CountOfSmallerNumbersAfterSelf, TEST_2) {
    const std::string input = "[-1]";
    const std::string output = "[0]";

    testLC0315(input, output);
}

TEST(LC0315_CountOfSmallerNumbersAfterSelf, TEST_3) {
    const std::string input = "[-1,-1]";
    const std::string output = "[0,0]";

    testLC0315(input, output);
}
