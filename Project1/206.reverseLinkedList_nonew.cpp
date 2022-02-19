#include "stddef.h"
#include <cstdio>



struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


void printList(ListNode* list) {
    ListNode* node = list;
    while (node) {
        printf("%d", node->val);
        node = node->next;
    }
}





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

void main() {
    Solution sol;
    ListNode* node = new ListNode(1);
    ListNode* head = node;
    node->next = new ListNode(2);
    node = node->next;

    sol.reverseList(head);
}