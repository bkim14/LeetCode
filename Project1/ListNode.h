#pragma once
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
};