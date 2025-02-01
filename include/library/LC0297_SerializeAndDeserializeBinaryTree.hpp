#pragma once

#include <datatype/TreeNode.hpp>
#include <string>

namespace LC0297 {
    std::string serialize(Datatype::TreeNode* root);
    Datatype::TreeNode* deserialize(std::string data);
}
