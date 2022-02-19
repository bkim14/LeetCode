
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* running_node;
        ListNode* head;
        if (list1->val < list2->val) {
            running_node = list1;
            list1 = list1->next;
        }
        else {
            running_node = list2;
            list2 = list2->next;
        }
        head = running_node;
        while (list1 && list2) {

            if (list1->val < list2->val) {
                running_node->next = list1;
                list1 = list1->next;
            }
            else {
                running_node->next = list2;
                list2 = list2->next;
            }
            running_node = running_node->next;
        }
        while (list1) {
            running_node->next = list1;
            list1 = list1->next;
            running_node = running_node->next;
        }
        while (list2) {
            running_node->next = list2;
            list2 = list2->next;
            running_node = running_node->next;
        }
        return head;
    }

};

int main() {
    ListNode* node=new ListNode(0);
    ListNode* nodee = NULL;
    Solution sol;
    printList(sol.mergeTwoLists(node, nodee));

}