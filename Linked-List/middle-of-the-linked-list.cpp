//Problem Statement
/*
Given a non-empty, singly linked list with head node head, return a middle node of linked list.

If there are two middle nodes, return the second middle node.
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
    ListNode *middleNode(ListNode *head)
    {
        //Normal approach : calculate total count and iteratre upto half of it
        /* int n=0;
        ListNode* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        if(n==0) return head;
        if(n==1) return head;
        int x=(n/2);
        temp=head;
        for(int i=0;i<x;i++){
            temp=temp->next;
        }
        return temp;*/
        //fast slow pointer approach
        ListNode *first = head, *second = head;
        while (second && second->next)
        {
            first = first->next;
            second = second->next->next;
        }
        return first;
    }
};