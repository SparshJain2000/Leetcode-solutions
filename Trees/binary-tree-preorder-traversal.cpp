//Problem Statement
//Given a binary tree, return the preorder traversal of its nodes' values.

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
    void preorder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;
        arr.push_back(root->val);
        preorder(root->left, arr);
        preorder(root->right, arr);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> temp;
        preorder(root, temp);
        return temp;
    }
};