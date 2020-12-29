//Problem Statement
/*
Reverse a singly linked list.
*/

#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
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

   public:
    void reorderList(ListNode *head) {
        if (!head) return;
        ListNode *middle = head, *fast = head;
        while (middle && fast && fast->next) middle = middle->next, fast = fast->next->next;
        ListNode *end = middle;
        middle->next = reverseList(middle->next);
        middle = middle->next;
        ListNode *f = head;
        while (middle && f) {
            ListNode *temp = middle->next;

            middle->next = f->next;
            f->next = middle;

            f = middle->next;
            middle = temp;
        }
        while (f != end) f = f->next;
        if (f) f->next = NULL;
    }
};

// 1 2 3   5 4
// 1 5 2 3  4
// 1 5 2 4 3