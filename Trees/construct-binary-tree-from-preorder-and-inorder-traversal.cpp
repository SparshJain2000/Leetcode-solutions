//Problem Statement
//Given inorder and preorder traversal of a tree, construct the binary tree.

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
    TreeNode *buildTree(vector<int> preorder, vector<int> inorder)
    {
        if (!preorder.size() || !inorder.size())
            return NULL;

        TreeNode *root = new TreeNode(preorder.at(0));
        int i = find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
        vector<int> left(inorder.begin(), inorder.begin() + i);
        vector<int> right(inorder.begin() + i + 1, inorder.end());

        root->left = buildTree(vector<int>(preorder.begin() + 1, preorder.begin() + left.size() + 1), left);

        root->right = buildTree(vector<int>(preorder.begin() + left.size() + 1, preorder.end()), right);
        return root;
    }
};