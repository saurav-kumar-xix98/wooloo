#pragma once

#include <datatype/TreeNode.hpp>

namespace Util::TreeNode {
    void deleteTree(Datatype::TreeNode* root);
    void assertTreeNodeEq(Datatype::TreeNode* root1, Datatype::TreeNode* root2);
}