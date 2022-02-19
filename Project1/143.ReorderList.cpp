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

    void reorderList(ListNode* head) {
        if (!head) return;
        if (!head->next) return;

        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* tail = NULL;
        while (1) {
            if (!fast) break;
            if (!fast->next) {
                tail = fast;
                break;
            }
            slow = slow->next;
            if (!fast->next->next) tail = fast->next;
            fast = fast->next->next;
        }

        reverseList(slow);
        ListNode* first = head;
        ListNode* second = tail;

        while (1) {
            if (first == second) break;
            if (first->next == second) break;
            ListNode* temp1 = first;
            ListNode* temp2 = second;
            first = first->next;
            second = second->next;
            temp1->next = temp2;
            temp2->next = first;
        }
    }
};

void main() {

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = node1->next = new ListNode(2);
    ListNode* node3 = node2->next = new ListNode(3);
    ListNode* node4 = node3->next = new ListNode(4);

    Solution sol;
    sol.reorderList(node1);
}