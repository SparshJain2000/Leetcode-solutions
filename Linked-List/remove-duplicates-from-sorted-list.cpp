//Problem Statement
/*
Given a sorted linked list, delete all duplicates such that each element appear only once.
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *temp = head;
        if (head == NULL)
            return head;
        while (temp->next != NULL) {
            bool flag = false;
            if (temp->val == temp->next->val) {
                flag = true;
                temp->next = temp->next->next;
            }
            if (!flag)
                temp = temp->next;
            if (temp == NULL)
                break;
        }
        return head;
    }
};