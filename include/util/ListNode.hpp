#pragma once

#include <datatype/ListNode.hpp>

namespace Util::ListNode {
    void deleteList(Datatype::ListNode* head);
    void assertListNodeEq(Datatype::ListNode* head1, Datatype::ListNode* head2);
}