#include "stddef.h"
#include <cstdio>
#include "ListNode.h"


class Solution {
public:


    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* start = new ListNode(-1,head);

        ListNode* fast = start;
        ListNode* slow = start;
        for (int i = 0;i <= n;i++) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
};

int main() {

    ListNode* node1 = new ListNode(1);
    ListNode* node2 = node1->next = new ListNode(2);

    Solution sol;
   
    printList(sol.removeNthFromEnd(node1, 2));

    return 0;
}