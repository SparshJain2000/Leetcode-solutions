//Problem Statement
/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *ptr1 = head;
        ListNode *ptr2;
        ListNode *temp = NULL;

        while (ptr1 != NULL)
        {
            if (ptr1->next == NULL)
                break;
            ptr2 = ptr1->next;
            ptr1->next = ptr2->next;
            ptr2->next = ptr1;
            if (temp != NULL)
                temp->next = ptr2;
            else
                head = ptr2;
            temp = ptr1;

            ptr1 = ptr1->next;
        }
        return head;
    }
};