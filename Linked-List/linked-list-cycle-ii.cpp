//Problem Statement
/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter
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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *start = head;
        ListNode *first = head;
        ListNode *second = head;
        while (second && second->next)
        {
            first = first->next;
            second = second->next->next;
            if (first == second)
            {
                while (start != first)
                    first = first->next, start = start->next;
                return start;
            }
        }
        return NULL;
    }
};