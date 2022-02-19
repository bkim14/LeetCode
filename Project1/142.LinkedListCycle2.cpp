#include "stddef.h"
#include <cstdio>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


void printList(ListNode* list) {
    ListNode* node = list;
    while (node) {
        printf("%d", node->val);
        node = node->next;
    }
}

ListNode* slow(ListNode* node) {
    return node->next||NULL;
    return NULL;
}

ListNode* fast(ListNode* node) {
    if (node && node->next) return node->next->next;
    return NULL;
}
class Solution {

    ListNode* findStartNode(ListNode* node1, ListNode* node2) {
        while (node1 != node2) {
            node1 = slow(node1);
            node2 = slow(node2);
        }
        if (node1 == node2) return node1;
        return NULL;
    }
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return NULL;
        ListNode* fastNode = fast(head);
        ListNode* slowNode = slow(head);
        while (slowNode && fastNode) {
            if (slowNode == fastNode) return findStartNode(slowNode, head);
            slowNode = slow(slowNode);
            fastNode = fast(fastNode);
        }
        return NULL;
    }

};

int main() {

    ListNode* node1 = new ListNode(3);
    ListNode* node2= node1->next = new ListNode(2);
    ListNode* node3 = node2 ->next = new ListNode(0);
    ListNode* node4 = node3->next = new ListNode(-4);
    node4->next = node2;
    Solution sol;
    printf("%d",sol.detectCycle(node1)->val);

    return 0;
}