#include <library/LC0315_CountOfSmallerNumbersAfterSelf.hpp>

namespace LC0315 {
    void merge(std::vector<int> &nums, std::vector<size_t> &indices, const size_t l, const size_t m, const size_t r, std::vector<int> &ans) {
        size_t i = 0, i1 = l, i2 = m;
        std::vector<size_t> merged(r - l);

        while (i1 < m && i2 < r) {
            if (nums[indices[i1]] <= nums[indices[i2]]) {
                ans[indices[i1]] += i2 - m;
                merged[i++] = indices[i1++];
            } else {
                merged[i++] = indices[i2++];
            }
        }

        while (i1 < m) {
            ans[indices[i1]] += i2 - m;
            merged[i++] = indices[i1++];
        }

        while (i2 < r) {
            merged[i++] = indices[i2++];
        }

        for (int i = l; i < r; ++i) {
            indices[i] = merged[i - l];
        }
    }

    void mergeSort(std::vector<int> &nums, std::vector<size_t> &indices, const size_t l, const size_t r, std::vector<int> &ans) {
        if (r - l < 2)
            return;

        const size_t m = (l + r) / 2;

        mergeSort(nums, indices, l, m, ans);
        mergeSort(nums, indices, m, r, ans);

        merge(nums, indices, l, m, r, ans);
    }
}

std::vector<int> LC0315::countSmaller(std::vector<int> &nums) {
    std::vector<int> ans(nums.size(), 0);
    std::vector<size_t> indices(nums.size());
    for (size_t i = 0; i < indices.size(); ++i)
        indices[i] = i;
    mergeSort(nums, indices, 0, nums.size(), ans);
    return ans;
}
