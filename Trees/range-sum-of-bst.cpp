//Problem Statement
/*
Given the root node of a binary search tree, return the sum of values of all nodes with a value in the range [low, high].
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
    void preorder(TreeNode *root, int low, int high, int &ans)
    {
        if (root)
        {
            if (root->val >= low && root->val <= high)
                ans += root->val;
            if (root->val > low)
                preorder(root->left, low, high, ans);
            if (root->val < high)
                preorder(root->right, low, high, ans);
        }
    }

public:
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int ans = 0;
        preorder(root, low, high, ans);
        return ans;
    }
};