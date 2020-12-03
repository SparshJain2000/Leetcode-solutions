//Problem Statement
/*
Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.
The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.
*/

#include <bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
    TreeNode *current;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        root->left = NULL;
        current->right = root;
        current = root;
        inorder(root->right);
    }

public:
    TreeNode *increasingBST(TreeNode *root)
    {
        if (!root)
            return root;
        TreeNode *node = new TreeNode(0);
        current = node;
        inorder(root);
        return node->right;
    }
};