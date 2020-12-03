
//Problem Statement
/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.
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
// Definition for Tree Node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    TreeNode *construct(ListNode *head, ListNode *tail)
    {
        if (head == tail)
            return NULL;
        if (head && head->next == tail)
            return new TreeNode(head->val);
        ListNode *slow = head, *fast = head;
        while (fast != tail && fast->next != tail)
            slow = slow->next, fast = fast->next->next;
        return new TreeNode(slow->val, construct(head, slow), construct(slow->next, tail));
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return construct(head, NULL);
    }
};