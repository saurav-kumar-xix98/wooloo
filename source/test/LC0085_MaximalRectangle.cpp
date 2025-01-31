#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC0085_MaximalRectangle.hpp>

void testLC0085(const std::string &input, const int &expected) {
    const auto matrix = Util::Parser::parse<std::vector<std::vector<char>>>(input);

    int result = LC0085::maximalRectangle(matrix);
    ASSERT_EQ(expected, result);
}

TEST(LC0085_MaximalRectangle, TEST_1) {
    const std::string input = "[[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]]";
    const int output = 6;

    testLC0085(input, output);
}

TEST(LC0085_MaximalRectangle, TEST_2) {
    const std::string input = "[[0]]";
    const int output = 0;

    testLC0085(input, output);
}

TEST(LC0085_MaximalRectangle, TEST_3) {
    const std::string input = "[[1]]";
    const int output = 1;

    testLC0085(input, output);
}
