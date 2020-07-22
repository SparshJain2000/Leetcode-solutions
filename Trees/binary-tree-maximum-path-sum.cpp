//Problem Statement
/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
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
    int util(TreeNode *root, int &res)
    {
        if (root == NULL)
            return 0;
        int l = util(root->left, res);
        int r = util(root->right, res);
        int s = max(max(r, l) + root->val, root->val);
        int t = max(s, r + l + root->val);
        res = max(res, t);
        return s;
    }
    int maxPathSum(TreeNode *root)
    {
        int res = INT_MIN;
        util(root, res);
        return res;
    }
};