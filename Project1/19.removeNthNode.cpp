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
};

class Solution {
public:
    int remove_no = 0;
    int recur(ListNode* curr) {
        if (!curr) {
            return 0;
        }
        int cnt = recur(curr->next);
        if (remove_no == cnt) {
            curr->next = curr->next->next;
        }
        return cnt+1;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        if (!head->next) return NULL;
        remove_no = n;
        recur(head);
        return head;
    }
};

int main() {

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = node1->next = new ListNode(2);
    ListNode* node3 = node2->next = new ListNode(3);
    ListNode* node4 = node3->next = new ListNode(4);
    ListNode* node5 = node4->next = new ListNode(5);

    Solution sol;
    sol.removeNthFromEnd(node1,2);

    return 0;
}