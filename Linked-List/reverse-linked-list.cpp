//Problem Statement
/*
Reverse a singly linked list.
*/

#include <bits/stdc++.h>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
   public:
    ListNode *reverseList(ListNode *head) {
        ListNode *temp = head;
        ListNode *pre = NULL;
        while (temp != NULL) {
            ListNode *x = temp;
            temp = temp->next;
            x->next = pre;
            pre = x;
        }
        head = pre;
        return head;
    }
};