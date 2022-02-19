#include "stddef.h"
#include <cstdio>
#include <vector>

using namespace std;

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



class Solution {
public:
    vector<ListNode*> list;

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

    ListNode* merge(int left, int right) {

        if (left == right) return list[left];
        int mid = (left + right) >> 1;
        ListNode* node1 = merge(left, mid);
        ListNode* node2 = merge(mid + 1, right);
        return mergeTwoLists( node1,node2 );

    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (!lists.size()) return NULL;
        list = lists;
        return merge(0, list.size() - 1);
    }
  
};

int main() {
    vector<ListNode*> lists;
    ListNode* node11 = new ListNode(1);
    ListNode* node12 = node11->next = new ListNode(4);
    ListNode* node13 = node12->next = new ListNode(5);

    ListNode* node21 = new ListNode(1);
    ListNode* node22 = node21->next = new ListNode(3);
    ListNode* node23 = node22->next = new ListNode(4);

    ListNode* node31 = new ListNode(2);
    ListNode* node32 = node31->next = new ListNode(6);

    lists.push_back(node11);
    lists.push_back(node21);
    lists.push_back(node31);
    Solution sol;
    printList(sol.mergeKLists(lists));
}