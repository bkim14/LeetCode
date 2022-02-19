#include "stddef.h"
#include <cstdio>
#include "ListNode.h"

 

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