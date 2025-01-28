#include <util/ListNode.hpp>
#include <gtest/gtest.h>

void Util::ListNode::deleteList(Datatype::ListNode *head) {
    while (head != nullptr) {
        Datatype::ListNode* temp = head->next;
        delete head;
        head = temp;
    }
}

void Util::ListNode::assertListNodeEq(Datatype::ListNode *head1, Datatype::ListNode *head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1 == head2)
            return;
        ASSERT_EQ(head1->val, head2->val);
        head1 = head1->next;
        head2 = head2->next;
    }

    ASSERT_EQ(head1, head2);
}
