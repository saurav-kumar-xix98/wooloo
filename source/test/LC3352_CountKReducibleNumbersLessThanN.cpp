#include <gtest/gtest.h>
#include <util/Parser.hpp>
#include <library/LC3352_CountKReducibleNumbersLessThanN.hpp>

void testLC3352(const std::string &s, int k, int output) {
    const auto result = LC3352::countKReducibleNumbers(s, k);
    ASSERT_EQ(output, result);
}

TEST(LC3352_CountKReducibleNumbersLessThanN, TEST_1) {
    const std::string s = "111";
    const int k = 1;
    const int output = 3;

    testLC3352(s, k, output);
}

TEST(LC3352_CountKReducibleNumbersLessThanN, TEST_2) {
    const std::string s = "1000";
    const int k = 2;
    const int output = 6;

    testLC3352(s, k, output);
}

TEST(LC3352_CountKReducibleNumbersLessThanN, TEST_3) {
    const std::string s = "1";
    const int k = 3;
    const int output = 0;

    testLC3352(s, k, output);
}
