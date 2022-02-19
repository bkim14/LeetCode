#include "stddef.h"
#include <cstdio>
#include "ListNode.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        ListNode* curr = NULL;
        ListNode* next = NULL;
        while (node) {
            curr = new ListNode(node->val);
            curr->next = next;
            next = curr;
            node = node->next;
        }
        printList(curr);
        return curr;
    }
};