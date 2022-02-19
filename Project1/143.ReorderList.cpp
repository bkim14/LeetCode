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
            return 1;
        }
        int cnt=recur(curr->next);
        if (remove_no == cnt-1) {
            curr->next = curr->next->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return NULL;
        if (!head->next) return NULL;
        recur(head);
        return head;
    }
};