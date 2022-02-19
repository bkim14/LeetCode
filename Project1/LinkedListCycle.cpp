#include "stddef.h"
#include <cstdio>

  struct ListNode {
      int val;
      ListNode *next;
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
      if (node) return node->next;
      return NULL;
  }

  ListNode* fast(ListNode* node) {
      if (node && node->next) return node->next->next;
      return NULL;
  }

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        if (!head->next) return false;
        ListNode* fastNode = fast(head);
        ListNode* slowNode = slow(head);
        while (slowNode && fastNode) {
            if (slowNode == fastNode) return true;
            slowNode = slow(slowNode);
            fastNode = fast(fastNode);
        }
        return false;
    }
};