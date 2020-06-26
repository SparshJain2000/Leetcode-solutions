//Problem Statement
/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
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
            temp2->next = mergeTwoLists(temp2->next, temp1);
            return temp2;
        }
        else
        {
            temp1->next = mergeTwoLists(temp1->next, temp2);
            return temp1;
        }
        return NULL;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        ListNode *head = lists.at(0);
        for (int i = 1; i < lists.size(); i++)
        {
            head = mergeTwoLists(head, lists.at(i));
        }
        return head;
    }
};