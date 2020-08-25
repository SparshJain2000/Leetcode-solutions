//Problem Statement
/*
Given a singly linked list, determine if it is a palindrome.
*/
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
*/
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        int n = 0;
        ListNode *temp = head;
        if (!head)
            return true;
        while (temp != NULL)
            temp = temp->next, n++;
        int x = 0;
        ListNode *pre = NULL;
        ListNode *ptr = head;
        while (x < n / 2)
        {
            ListNode *temp = ptr;
            ptr = ptr->next;
            temp->next = pre;
            pre = temp;
            x++;
        }
        if (n & 1)
            ptr = ptr->next;
        while (ptr != NULL || pre != NULL)
        {
            if (ptr->val != pre->val)
                return false;
            ptr = ptr->next;
            pre = pre->next;
        }
        return true;
    }
};