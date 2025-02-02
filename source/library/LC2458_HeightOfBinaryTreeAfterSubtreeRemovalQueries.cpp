#include <library/LC2458_HeightOfBinaryTreeAfterSubtreeRemovalQueries.hpp>

namespace LC2458 {
    void traverse(Datatype::TreeNode* node, std::vector<int> &nodeLevelMap, std::vector<int> &nodeDepthMap, std::vector<std::vector<int>> &levelMaxDepthMap, int level) {
        if (node == nullptr)
            return;

        traverse(node->left, nodeLevelMap, nodeDepthMap, levelMaxDepthMap, level + 1);
        traverse(node->right, nodeLevelMap, nodeDepthMap, levelMaxDepthMap, level + 1);
        if (nodeLevelMap.size() < node->val)
            nodeLevelMap.resize(node->val);
        if (nodeDepthMap.size() < node->val)
            nodeDepthMap.resize(node->val);

        nodeLevelMap[node->val - 1] = level;

        int leftDepth = node->left != nullptr ? nodeDepthMap[node->left->val - 1] : 0;
        int rightDepth = node->right != nullptr ? nodeDepthMap[node->right->val - 1] : 0;
        int nodeDepth = 1 + std::max(leftDepth, rightDepth);
        nodeDepthMap[node->val - 1] = nodeDepth;

        if (levelMaxDepthMap.size() <= level)
            levelMaxDepthMap.resize(level + 1);

        if (levelMaxDepthMap[level].size() < 1 || levelMaxDepthMap[level][0] < nodeDepth)
            levelMaxDepthMap[level].insert(levelMaxDepthMap[level].begin(), nodeDepth);
        else if (levelMaxDepthMap[level].size() < 2 || levelMaxDepthMap[level][1] < nodeDepth)
            levelMaxDepthMap[level].insert(levelMaxDepthMap[level].begin() + 1, nodeDepth);

        if (levelMaxDepthMap[level].size() > 2)
            levelMaxDepthMap[level].resize(2);
    }
}

std::vector<int> LC2458::treeQueries(Datatype::TreeNode *root, std::vector<int> &queries) {
    std::vector<int> nodeLevelMap;
    std::vector<int> nodeDepthMap;
    std::vector<std::vector<int>> levelMaxDepthMap;

    traverse(root, nodeLevelMap, nodeDepthMap, levelMaxDepthMap, 0);
    int rootDepth = nodeDepthMap[root->val - 1];

    std::vector<int> ans;
    ans.reserve(queries.size());
    for (auto node : queries) {
        int nodeLevel = nodeLevelMap[node - 1];
        int nodeDepth = nodeDepthMap[node - 1];
        const auto& levelMaxDepth = levelMaxDepthMap[nodeLevel];
        if (levelMaxDepth.size() == 1)
            ans.push_back(nodeLevel - 1);
        else if (levelMaxDepth[0] == nodeDepth)
            ans.push_back(rootDepth - levelMaxDepth[0] + levelMaxDepth[1] - 1);
        else
            ans.push_back(rootDepth - 1);

    }
    return ans;
}
