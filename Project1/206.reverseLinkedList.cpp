#include "stddef.h"
#include <cstdio>



  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
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