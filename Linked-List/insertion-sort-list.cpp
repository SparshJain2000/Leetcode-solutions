
//Problem Statement
/*
Sort a linked list using insertion sort
Algorithm of Insertion Sort:

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
It repeats until no input elements remain.
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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode *ansHead = NULL;
        while (head)
        {
            if (!ansHead)
                ansHead = new ListNode(head->val);

            else
            {
                ListNode *temp = ansHead;
                ListNode *newNode = new ListNode(head->val);
                if (temp->val > head->val)
                    newNode->next = ansHead, ansHead = newNode;
                else
                {
                    while (temp->next && temp->next->val < head->val)
                        temp = temp->next;

                    newNode->next = temp->next;
                    temp->next = newNode;
                }
            }

            head = head->next;
        }
        return ansHead;

        // ListNode *pre = NULL, *temp = head;
        // while (temp)
        // {

        //     if (pre)
        //     {
        //         ListNode *ptr = head, *ptr1 = NULL;
        //         while (ptr != temp && ptr->val < temp->val)
        //             ptr1 = ptr, ptr = ptr->next;

        //         if (ptr1)
        //             ptr1->next = temp;
        //         if (pre)
        //             pre->next = temp->next;
        //         temp->next = ptr;
        //         if (!ptr1)
        //             head = temp;
        //     }
        //     pre = temp;
        //     temp = temp->next;
        // }
    }
};