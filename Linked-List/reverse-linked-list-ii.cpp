//Problem Statement
/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n)
            return head;
        ListNode *first = head, *temp = NULL;
        for (int i = 2; i <= m; i++)
            temp = first, first = first->next;
        ListNode *f2 = first;
        ListNode *ptr = first, *pre = NULL;
        int count = m;
        while (count < n) {
            ptr = first->next;
            first->next = pre;
            pre = first;
            first = ptr;
            count++;
        }
        temp ? temp->next = first : head = first;
        f2->next = first->next;
        first->next = pre;
        return head;
    }
};