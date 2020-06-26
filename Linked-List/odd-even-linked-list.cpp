//Problem Statement
/*
Given a singly linked list, group all odd nodes together followed by the even nodes.
Please note here we are talking about the node number and not the value in the nodes.
*/
#include <bits/stdc++.h>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *last = head;
        if (!head)
            return head;
        while (last->next)
            last = last->next;
        if (last == head)
            return head;
        ListNode *f = head;
        ListNode *l = last;
        while (f && l)
        {
            l->next = f->next;
            l = l->next;
            f->next = l->next;
            f = f->next;
            if (f == last || l == last)
                break;
        }
        l->next = NULL;
        return head;
    }
};
