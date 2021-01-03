//Problem Statement
/*
You are given the root of a binary tree where each node has a value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
Return the sum of these numbers. The answer is guaranteed to fit in a 32-bits integer.
*/
#include <bits/stdc++.h>
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
    void dfs(TreeNode *root, int &ans, int current) {
        if (root) {
            current = current * 2 + root->val;
            if (root->left)
                dfs(root->left, ans, current);
            if (root->right)
                dfs(root->right, ans, current);
            if (!root->left && !root->right)
                ans += current;
        }
    }

   public:
    int sumRootToLeaf(TreeNode *root) {
        int ans = 0;
        int current = 0;
        dfs(root, ans, current);
        return ans;
    }
};