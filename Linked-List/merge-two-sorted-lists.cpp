//Problem Statement
/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        if (temp1 == NULL)
            return l2;
        if (temp2 == NULL)
            return l1;
        ListNode *ptr = NULL;
        if (temp1->val >= temp2->val)
        {
            ptr = temp2;
            temp2 = temp2->next;
        }
        else
        {
            ptr = temp1;
            temp1 = temp1->next;
        }
        ListNode *head = ptr;
        while (temp1 != NULL && temp2 != NULL)
        {
            if (temp1->val >= temp2->val)
            {
                ptr->next = temp2;
                temp2 = temp2->next;
            }
            else
            {
                ptr->next = temp1;
                temp1 = temp1->next;
            }
            ptr = ptr->next;
        }
        if (temp1 != NULL)
            ptr->next = temp1;
        if (temp2 != NULL)
            ptr->next = temp2;
        return head;
    }
};