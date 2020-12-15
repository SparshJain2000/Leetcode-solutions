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
};
class Solution {
    void dfs(TreeNode *original, TreeNode *cloned, TreeNode *&target) {
        if (original && cloned) {
            if (original == target) {
                target = cloned;
                return;
            }
            dfs(original->left, cloned->left, target);
            dfs(original->right, cloned->right, target);
        }
    }

   public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        dfs(original, cloned, target);
        return target;
    }
};