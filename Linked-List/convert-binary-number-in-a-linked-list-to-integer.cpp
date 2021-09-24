
//Problem Statement
/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.
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
    int getDecimalValue(ListNode *head) {
        int ans = head->val;
        while (head->next) {
            ans = ans * 2 + head->next->val;
            head = head->next;
        }
        return ans;
    }
};