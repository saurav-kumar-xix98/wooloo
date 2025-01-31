#include <library/LC0085_MaximalRectangle.hpp>

int LC0085::maximalRectangle(const std::vector<std::vector<char>> &matrix) {
        if (matrix.empty() || matrix.front().empty())
            return 0;

        const size_t rowCount = matrix.size();
        const size_t colCount = matrix.front().size();

        std::vector reducedVector(colCount, 0);

        int ans = 0;

        for (int r = 0; r < rowCount; ++r) {
            std::vector<int> left(colCount);
            std::vector<int> right(colCount);

            for (int c = 0; c < colCount; ++c) {
                if (matrix[r][c] == '1')
                    reducedVector[c]++;
                else
                    reducedVector[c] = 0;
            }

            for (int c = 0; c < colCount; ++c) {
                int lIndex = c - 1;
                while (lIndex >= 0 && reducedVector[lIndex] >= reducedVector[c])
                    lIndex = left[lIndex];
                left[c] = lIndex;

                int rIndex = static_cast<int>(colCount) - c;
                while (rIndex < colCount && reducedVector[rIndex] >= reducedVector[colCount - 1 - c])
                    rIndex = right[rIndex];
                right[colCount - 1 - c] = rIndex;
            }

            for (int c = 0; c < colCount; ++c) {
                if (const int currArea = reducedVector[c] * (right[c] - left[c] - 1);
                    currArea > ans)
                    ans = currArea;
            }
        }

        return ans;
}
