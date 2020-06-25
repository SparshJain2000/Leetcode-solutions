//Problem Statement
//Given inorder and postorder traversal of a tree, construct the binary tree.

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
    TreeNode *buildTree(vector<int> inorder, vector<int> postorder)
    {
        if (!postorder.size() || !inorder.size())
            return NULL;
        TreeNode *root = new TreeNode(postorder.back());
        int i = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();

        vector<int> left(inorder.begin(), inorder.begin() + i);
        vector<int> right(inorder.begin() + i + 1, inorder.end());

        root->right = buildTree(right, vector<int>(postorder.begin() + left.size(), postorder.begin() + left.size() + right.size()));
        root->left = buildTree(left, vector<int>(postorder.begin(), postorder.begin() + left.size()));

        return root;
    }
};