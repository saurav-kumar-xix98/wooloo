#include <library/LC1036_EscapeALargeMaze.hpp>
#include <unordered_set>
#include <array>
#include <stack>
#include <algorithm>

template <typename T, std::size_t N>
struct std::hash<std::array<T, N>> {
    size_t operator()(const std::array<T, N>& arr) const {
        size_t hash_value = 0;
        for (const auto& elem : arr) {
            hash_value ^= std::hash<T>{}(elem) + 0x9e3779b9 + (hash_value << 6) + (hash_value >> 2);
        }
        return hash_value;
    }
};

namespace LC1036 {
    bool canReachDistOrPoint(const std::array<int, 2> &src, const std::unordered_set<std::array<int, 2>> &blocks, int targetDist, const std::array<int, 2> &des) {
        const auto distance = [](const std::array<int, 2> &lhs, const std::array<int, 2> &rhs) {
            return std::abs(lhs[0] - rhs[0]) + std::abs(lhs[1] - rhs[1]);
        };
        std::stack<std::array<int, 2>> toVisit;
        std::unordered_set<std::array<int, 2>> markedForVisit;
        constexpr std::array<std::array<int, 2>, 4> dirs = {{ {{-1, 0}}, {{1, 0}}, {{0, -1}}, {{0, 1}} }};
        toVisit.push(src);
        markedForVisit.insert(src);
        while (!toVisit.empty()) {
            const auto curr = toVisit.top();
            toVisit.pop();
            if (distance(curr, src) >= targetDist || distance(curr, des) == 0)
                return true;
            for (const auto &dir : dirs) {
                std::array<int, 2> next = { curr[0] + dir[0], curr[1] + dir[1] };
                if (next[0] < 0 || next[0] >= 1'000'000)
                    continue;
                if (next[1] < 0 || next[1] >= 1'000'000)
                    continue;
                if (markedForVisit.find(next) != markedForVisit.end())
                    continue;
                if (blocks.find(next) != blocks.end())
                    continue;
                toVisit.push(next);
                markedForVisit.insert(next);
            }
        }
        return false;
    }
}

bool LC1036::isEscapePossible(std::vector<std::vector<int>> &blocked, std::vector<int> &source, std::vector<int> &target) {
        std::unordered_set<std::array<int, 2>> blockedSet;
        for (const auto &block: blocked)
            blockedSet.insert({block[0], block[1]});

        return canReachDistOrPoint({source[0], source[1]}, blockedSet, 400, {target[0], target[1]}) && canReachDistOrPoint({target[0], target[1]}, blockedSet, 400, {source[0], source[1]});
}
