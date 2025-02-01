#include <util/TreeNode.hpp>
#include <gtest/gtest.h>

void Util::TreeNode::deleteTree(Datatype::TreeNode *root) {
    if (root == nullptr)
        return;
    
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void Util::TreeNode::assertTreeNodeEq(Datatype::TreeNode *root1, Datatype::TreeNode *root2) {
    if (root1 == nullptr && root2 == nullptr)
        return;
    
    ASSERT_TRUE(root1 != nullptr);
    ASSERT_TRUE(root2 != nullptr);

    ASSERT_EQ(root1->val, root2->val);

    assertTreeNodeEq(root1->left, root2->left);
    assertTreeNodeEq(root1->right, root2->right);
}
