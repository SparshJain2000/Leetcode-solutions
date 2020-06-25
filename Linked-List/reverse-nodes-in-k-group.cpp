//Problem Statement
/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *ht = NULL;
        int n = 0;
        while (temp != NULL)
        {
            n++;
            temp = temp->next;
        }
        temp = head;
        while (n >= k)
        {
            ListNode *h1 = NULL;
            for (int i = 0; i < k; i++)
            {
                ListNode *x = new ListNode(temp->val);
                x->next = h1;
                h1 = x;
                temp = temp->next;
            }
            if (ht == NULL)
                ht = h1;
            else
            {
                ListNode *c = ht;
                while (c->next != NULL)
                    c = c->next;
                c->next = h1;
            }
            n -= k;
            if (k > n)
                break;
        }
        ListNode *c = ht;
        while (c->next != NULL)
            c = c->next;
        while (temp != NULL)
        {
            c->next = temp;
            temp = temp->next;
            c = c->next;
        }

        head = ht;
        return head;
    }
};