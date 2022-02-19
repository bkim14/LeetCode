#include "stddef.h"
#include <cstdio>
#include "ListNode.h"

class Solution {
public:

    ListNode* reverse_node = NULL;
    void recur(ListNode* orig_ptr, ListNode* rev_ptr) {

        if (!orig_ptr) return;
        ListNode* new_head = orig_ptr;
        orig_ptr = orig_ptr->next;
        new_head->next = reverse_node;
        reverse_node = new_head;
        recur(orig_ptr, new_head);

    }

    ListNode* reverseList(ListNode* head) {
        recur(head, reverse_node);
        return reverse_node;
    }
};