#include <gtest/gtest.h>
#include <library/LC1808_MaximizeNumberOfNiceDivisors.hpp>

void testLC1808(const int input, const int output) {
    const auto result = LC1808::maxNiceDivisors(input);
    ASSERT_EQ(output, result);
}

TEST(LC1808_MaximizeNumberOfNiceDivisors, TEST_1) {
    const int input = 5;
    const int output = 6;

    testLC1808(input, output);
}

TEST(LC1808_MaximizeNumberOfNiceDivisors, TEST_2) {
    const int input = 8;
    const int output = 18;

    testLC1808(input, output);
}
