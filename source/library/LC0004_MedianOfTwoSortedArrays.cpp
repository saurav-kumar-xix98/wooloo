#include <library/LC0004_MedianOfTwoSortedArrays.hpp>

namespace LC0004 {
    int findXthNum(const std::vector<int> &nums1, const std::vector<int> &nums2, int x) {
        const int n1 = nums1.size(), n2 = nums2.size();
        int l = std::max(x - n2, 0), r = std::min(n1, x + 1);
        while (l < r) {
            const int m1 = (l + r) / 2;
            const int m2 = x - m1;
            if (m2 < 0)
                r = m1;
            else if (m2 > n2)
                l = m1 + 1;
            else if (m2 != n2 && nums2[m2] < nums1[m1])
                r = m1;
            else if (m2 != 0 && nums2[m2 - 1] > nums1[m1])
                l = m1 + 1;
            else
                return m1;
        }
        return -1;
    }
}

double LC0004::findMedianSortedArrays(const std::vector<int> &nums1, const std::vector<int> &nums2) {
        const int n = nums1.size() + nums2.size();

        if (n % 2 == 1) {
            int index = findXthNum(nums1, nums2, n / 2);
            if (index != -1)
                return nums1[index];
            return nums2[findXthNum(nums2, nums1, n / 2)];
        }

        double ans = 0;
        int index = findXthNum(nums1, nums2, n / 2);
        if (index != -1)
            ans = nums1[index];
        else
            ans = nums2[findXthNum(nums2, nums1, n / 2)];

        index = findXthNum(nums1, nums2, n / 2 - 1);
        if (index != -1)
            ans += nums1[index];
        else
            ans += nums2[findXthNum(nums2, nums1, n / 2 - 1)];

        return ans / 2;
}
