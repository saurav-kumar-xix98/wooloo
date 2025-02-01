#include <library/LC0297_SerializeAndDeserializeBinaryTree.hpp>

namespace LC0297 {
    Datatype::TreeNode* deserializeUtil(std::string data, int& i) {
        char ch = data[i++];
        
        if (ch == ']')
            return nullptr;
        
        std::string val(1, ch);
        while(data[i] != '[')
            val.push_back(data[i++]);
        
        Datatype::TreeNode* root = new Datatype::TreeNode(std::stoi(val));

        i++;
        root->left = deserializeUtil(data, i);
        i++;
        root->right = deserializeUtil(data, i);
        i++;
        return root;
    }
}

std::string LC0297::serialize(Datatype::TreeNode *root) {
    if (root == nullptr)
        return "[]";

    return "[" + std::to_string(root->val) + serialize(root->left) + serialize(root->right) + "]";
}

Datatype::TreeNode *LC0297::deserialize(std::string data) {
    int i = 1;
    return deserializeUtil(data, i);
}
