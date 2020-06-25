//Problem Statement
//Given a linked list, rotate the list to the right by k places, where k is non-negative.

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !k)
            return head;
        ListNode *temp = head;
        int n = 1;
        while (temp->next != NULL)
        {
            temp = temp->next;
            n++;
        }
        temp->next = head;
        temp = head;
        for (int i = 0; i < (n - (k % n) - 1); i++)
            temp = temp->next;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};