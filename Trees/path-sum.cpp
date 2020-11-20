//Problem Statement
/*
Share
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.
*/
#include <bits/stdc++.h>
// Definition for a Node.
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;

    TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val, TreeNode *_left, TreeNode *_right, TreeNode *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
public:
    void util(TreeNode *root, int sum, bool &flag)
    {
        if (root)
        {
            if (root->val == sum && !root->left && !root->right)
            {
                flag = true;
                return;
            }
            util(root->left, sum - root->val, flag);
            util(root->right, sum - root->val, flag);
        }
    }

    bool hasPathSum(TreeNode *root, int sum)
    {
        bool flag = false;
        util(root, sum, flag);
        return flag;
    }
};