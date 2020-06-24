//Problem Statement-
//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

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
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = minDepth(root->left);
        int r = minDepth(root->right);
        if (!l)
            return r + 1;
        if (!r)
            return l + 1;
        if (l < r)
            return l + 1;
        return r + 1;
    }
};