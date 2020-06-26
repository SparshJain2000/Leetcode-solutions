//Problem Statement
/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.
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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *ah = new ListNode(0);
        ListNode *at = ah;
        ListNode *bh = new ListNode(0);
        ListNode *bt = bh;
        ListNode *temp = head;
        while (temp)
        {
            if (temp->val < x)
            {
                at->next = temp;
                at = at->next;
            }
            else
            {
                bt->next = temp;
                bt = bt->next;
            }
            temp = temp->next;
        }
        bt->next = NULL;
        at->next = bh->next;
        return ah->next;
    }
};