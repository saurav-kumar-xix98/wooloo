#include <library/LC0493_ReversePairs.hpp>

namespace LC0493 {
    int merge(std::vector<int> &nums, const size_t l, const size_t m, const size_t r) {
        std::vector<int> merged(r - l);
        size_t i = 0, i1 = l, i2 = m, i3 = m;
        int ans = 0;

        while (i1 < m && i2 < r) {
            if (nums[i1] <= nums[i2]) {
                while (i3 < r && (long long)nums[i1] > 2 * (long long)nums[i3])
                    i3++;
                ans += i3 - m;
                merged[i++] = nums[i1++];
            } else {
                merged[i++] = nums[i2++];
            }
        }

        while (i1 < m) {
            while (i3 < r && (long long)nums[i1] > 2 * (long long)nums[i3])
                i3++;
            ans += i3 - m;
            merged[i++] = nums[i1++];
        }

        while (i2 < r) {
            merged[i++] = nums[i2++];
        }

        for (size_t i = l; i < r; ++i)
            nums[i] = merged[i - l];

        return ans;
    }

    int mergeSort(std::vector<int> &nums, const size_t l, const size_t r) {
        if (r - l < 2)
            return 0;
        const size_t m = (l + r) / 2;
        int ans = 0;
        ans += mergeSort(nums, l, m);
        ans += mergeSort(nums, m, r);
        ans += merge(nums, l, m, r);
        return ans;
    }
};

int LC0493::reversePairs(std::vector<int> &nums) {
    return mergeSort(nums, 0, nums.size());
}
