//Problem Statement
/*
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
*/
#include <bits/stdc++.h>
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        else if (p != NULL && q != NULL)
        {
            if (p->val != q->val)
                return false;
            bool l = isSameTree(p->left, q->left);
            bool r = isSameTree(p->right, q->right);
            return l && r;
        }
        else
            return false;
    }
};