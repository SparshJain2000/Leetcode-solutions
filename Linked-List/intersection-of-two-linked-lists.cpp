
//Problem Statement
/*
Write a program to find the node at which the intersection of two singly linked lists begins.
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = 0;
        int sizeB = 0;
        ListNode *temp = headA;
        while (temp) temp = temp->next, sizeA++;
        temp = headB;
        while (temp) temp = temp->next, sizeB++;
        if (sizeA > sizeB) {
            for (int i = 0; i < sizeA - sizeB; i++) headA = headA->next;
            while (headA != headB) headA = headA->next, headB = headB->next;
        } else {
            for (int i = 0; i < sizeB - sizeA; i++) headB = headB->next;
            while (headA != headB) headA = headA->next, headB = headB->next;
        }

        return headA;
    }
};