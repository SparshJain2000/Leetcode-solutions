//Problem Statement
//Given a binary tree, return the postorder traversal of its nodes' values.

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
    void postorder(TreeNode *root, vector<int> &arr)
    {
        if (root == NULL)
            return;
        postorder(root->left, arr);
        postorder(root->right, arr);
        arr.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> arr;
        postorder(root, arr);
        return arr;
    }
};