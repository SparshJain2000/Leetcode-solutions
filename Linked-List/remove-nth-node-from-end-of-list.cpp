//Problem Statement
//Given a linked list, remove the n-th node from the end of list and return its head.

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        temp = head;
        if (n > count)
            return head;
        ListNode *ptr = NULL;
        for (int i = 0; i < count - n; i++)
        {
            ptr = temp;
            temp = temp->next;
        }
        if (ptr == NULL)
            head = temp->next;
        else
            ptr->next = temp->next;
        return head;
    }
};