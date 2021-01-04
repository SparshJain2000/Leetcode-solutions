//Problem Statement
/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/
#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class TreeNode {
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
class Solution {
    void util(TreeNode *root, int &y) {
        if (!root)
            return;
        util(root->right, y);
        y += root->val;
        root->val = y;
        util(root->left, y);
    }

   public:
    TreeNode *bstToGst(TreeNode *root) {
        int y = 0;
        util(root, y);
        return root;
    }
};