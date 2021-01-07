//Problem Statement
/*
We are given a linked list with head as the first node.  Let's number the nodes in the list: node_1, node_2, node_3, ... etc.

Each node may have a next larger value: for node_i, next_larger(node_i) is the node_j.val such that j > i, node_j.val > node_i.val, and j is the smallest possible choice.  If such a j does not exist, the next larger value is 0.

Return an array of integers answer, where answer[i] = next_larger(node_{i+1}).

Note that in the example inputs (not outputs) below, arrays such as [2,1,5] represent the serialization of a linked list with a head node value of 2, second node value of 1, and third node value of 5.
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
    vector<int> nextLargerNodes(ListNode *head) {
        vector<int> ans;
        while (head) {
            ListNode *temp = head->next;
            while (temp && temp->val <= head->val)
                temp = temp->next;
            (temp && temp->val > head->val) ? ans.push_back(temp->val) : ans.push_back(0);
            head = head->next;
        }
        return ans;
    }
};