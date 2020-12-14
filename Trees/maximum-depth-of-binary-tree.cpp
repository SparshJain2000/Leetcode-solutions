//Problem Statement
/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
#include <bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
   public:
    int maxDepth(TreeNode *root) {
        if (root == NULL)
            return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if (l > r)
            return l + 1;
        return r + 1;
    }
};