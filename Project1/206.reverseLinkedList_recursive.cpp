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

ListNode* ans = NULL;
ListNode* ans_curr = NULL;

void recur(ListNode* curr, bool isFirst) {
    if (!curr) {
        ans_curr = new ListNode;
        ans = ans_curr;
        return;
    }
    recur(curr->next,false);
    ans_curr->val = curr->val;
    if (!isFirst) {
        ans_curr->next = new ListNode;
        ans_curr = ans_curr->next;
    }
}

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        recur(head, true);
        printList(ans);
        return NULL;
    }
};

void main() {
    Solution sol;
    ListNode* node = new ListNode(1);
    ListNode* head = node;
    node->next = new ListNode(2);
    node = node->next;
    node->next = new ListNode(3);
    node = node->next;
    sol.reverseList(head);
}