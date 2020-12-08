//Problem Statement
/*
You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
*/

#include <bits/stdc++.h>
using namespace std;
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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *temp1 = list1;
        ListNode *temp2;

        while (temp1->next->val != a)
            temp1 = temp1->next;
        temp2 = temp1->next;
        while (temp2->val != b)
            temp2 = temp2->next;

        temp1->next = list2;
        while (list2->next)
            list2 = list2->next;
        list2->next = temp2->next;

        return list1;
    }
};