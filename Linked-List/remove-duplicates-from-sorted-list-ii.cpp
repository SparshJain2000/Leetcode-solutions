//Problem Statement
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.
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
        if (!head)
            return head;
        ListNode *b, *c, *a;
        a = NULL;
        b = head;
        c = b->next;
        while (c) {
            if (b->val == c->val) {
                while (c->next && b->val == c->next->val)
                    c = c->next;
                if (a)
                    a->next = c->next;
                b = c->next;
                c = b ? b->next : NULL;
                if (!a)
                    head = b;
            } else {
                a = b;
                b = c;
                c = c->next;
            }
        }
        return head;
    }
};