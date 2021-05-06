//Problem Statement
//Given inorder and preorder traversal of a tree, construct the binary tree.

#include <bits/stdc++.h>
//Definition for a binary tree node.
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
   public:
    TreeNode *buildTree(vector<int> preorder, vector<int> inorder) {
        if (!preorder.size() || !inorder.size())
            return NULL;
        TreeNode *root = new TreeNode(preorder[0]);
        int i = 0;
        for (i = 0; i < inorder.size(); i++)
            if (inorder[i] == root->val) break;
        vector<int> left(inorder.begin(), inorder.begin() + i);
        vector<int> right(inorder.begin() + i + 1, inorder.end());

        root->left = buildTree(vector<int>(preorder.begin() + 1, preorder.begin() + left.size() + 1), left);
        root->right = buildTree(vector<int>(preorder.begin() + left.size() + 1, preorder.end()), right);
        return root;
    }
};