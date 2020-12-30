//Problem Statement
/*
Given a binary search tree, return a balanced binary search tree with the same node values.
A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.
If there is more than one answer, return any of them.
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
    int util(TreeNode *root, bool &flag) {
        if (!flag) return -1;
        if (!root) return 0;
        int l = util(root->left, flag);
        int r = util(root->right, flag);

        flag &= abs(l - r) <= 1;
        return (l > r) ? l + 1 : r + 1;
    }
    bool isBalanced(TreeNode *root) {
        bool flag = true;
        util(root, flag);
        return flag;
    }
};