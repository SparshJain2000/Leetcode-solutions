//Problem Statement
/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
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
private:
    int length(ListNode *l)
    {
        ListNode *temp = l;
        int s = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            s++;
        }
        return s;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *ans;
        ListNode *tr;
        ListNode *tr1;
        ListNode *tr2;
        tr = NULL;
        tr1 = l1;
        tr2 = l2;
        int s1 = length(l1);
        int s2 = length(l2);
        if (s1 > s2)
        {
            int res = 0;
            int sum = 0;
            for (int i = 0; i < s2; i++)
            {
                sum = tr1->val + tr2->val + res;
                tr1 = tr1->next;
                tr2 = tr2->next;
                ListNode *newn = new ListNode((sum % 10));
                cout << newn->val << endl;
                if (tr == NULL)
                {
                    tr = newn;
                    ans = tr;
                }
                else
                {
                    tr->next = newn;
                    tr = tr->next;
                }
                res = sum / 10;
            }
            sum = 0;
            for (int i = s2; i < s1; i++)
            {
                sum = res + tr1->val;
                tr1 = tr1->next;
                ListNode *newn = new ListNode(sum % 10);
                if (tr == NULL)
                {
                    tr = newn;
                    ans = tr;
                }
                else
                {
                    tr->next = newn;
                    tr = tr->next;
                }
                res = sum / 10;
            }
            if (res != 0)
            {
                ListNode *newn = new ListNode(res);
                tr->next = newn;
                tr = tr->next;
            }
        }
        else if (s1 < s2)
        {
            int res = 0;
            int sum = 0;
            for (int i = 0; i < s1; i++)
            {
                sum = tr1->val + tr2->val + res;
                tr1 = tr1->next;
                tr2 = tr2->next;
                ListNode *newn = new ListNode((sum % 10));
                cout << newn->val << endl;
                if (tr == NULL)
                {
                    tr = newn;
                    ans = tr;
                }
                else
                {
                    tr->next = newn;
                    tr = tr->next;
                }
                res = sum / 10;
            }
            sum = 0;
            for (int i = s1; i < s2; i++)
            {
                sum = res + tr2->val;
                tr2 = tr2->next;
                ListNode *newn = new ListNode(sum % 10);
                if (tr == NULL)
                {
                    tr = newn;
                    ans = tr;
                }
                else
                {
                    tr->next = newn;
                    tr = tr->next;
                }
                res = sum / 10;
            }
            if (res != 0)
            {
                ListNode *newn = new ListNode(res);
                tr->next = newn;
                tr = tr->next;
            }
        }
        else if (s1 == s2)
        {
            int sum = 0;
            int res = 0;
            for (int i = 0; i < s1; i++)
            {
                sum = tr1->val + tr2->val + res;
                tr1 = tr1->next;
                tr2 = tr2->next;
                ListNode *newn = new ListNode((sum % 10));
                cout << newn->val << endl;
                if (tr == NULL)
                {
                    tr = newn;
                    ans = tr;
                }
                else
                {
                    tr->next = newn;
                    tr = tr->next;
                }
                res = sum / 10;
            }
            if (res != 0)
            {
                ListNode *newn = new ListNode(res);
                tr->next = newn;
                tr = tr->next;
            }
        }
        return ans;
    }
};
