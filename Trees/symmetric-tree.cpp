//Problem Statement
//Given a binary tree, check whether it is a mirror of itself(ie, symmetric around its center).

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
    bool isMirror(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        else if (p && q)
        {
            return (isMirror(p->left, q->right) && isMirror(p->right, q->left) && (p->val == q->val));
        }
        else
            return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root, root);
    }
};