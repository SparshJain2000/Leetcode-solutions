//Problem Statement
/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
*/

#include <bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
   public:
    int util(TreeNode *root, int &ans) {
        if (!root) return 0;
        int l = util(root->left, ans);
        int r = util(root->right, ans);
        int temp = max(max(l + root->val, r + root->val), root->val);
        ans = max(ans, max(temp, l + r + root->val));

        return temp;
    }
    int maxPathSum(TreeNode *root) {
        int ans = INT_MIN;
        util(root, ans);
        return ans;
    }
};