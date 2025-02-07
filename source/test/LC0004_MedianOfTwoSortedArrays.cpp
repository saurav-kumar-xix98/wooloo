#include <gtest/gtest.h>
#include <library/LC0004_MedianOfTwoSortedArrays.hpp>
#include <util/Parser.hpp>

void testLC0004(const std::string &input1, const std::string &input2, const double output) {
    const auto nums1 = Util::Parser::parse<std::vector<int>>(input1);
    const auto nums2 = Util::Parser::parse<std::vector<int>>(input2);

    const auto result = LC0004::findMedianSortedArrays(nums1, nums2);
    ASSERT_EQ(output, result);
}

TEST(LC0004_MedianOfTwoSortedArrays, TEST_1) {
    const std::string nums1 = "[1,3]";
    const std::string nums2 = "[2]";
    const double output = 2.0;

    testLC0004(nums1, nums2, output);
}

TEST(LC0004_MedianOfTwoSortedArrays, TEST_2) {
    const std::string nums1 = "[1,2]";
    const std::string nums2 = "[3,4]";
    const double output = 2.5;

    testLC0004(nums1, nums2, output);
}
