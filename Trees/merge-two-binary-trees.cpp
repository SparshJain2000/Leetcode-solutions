//Problem Statement
/*
    You are given two binary trees root1 and root2.
    Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.
    Return the merged tree.
    Note: The merging process must start from the root nodes of both trees.    
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
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
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (!root1 && !root2) return root1;
        if (root1)
            root1->val += (root2 ? root2->val : 0);
        else
            root1 = new TreeNode(root2->val);
        root1->left = mergeTrees(root1->left, root2 ? root2->left : NULL);
        root1->right = mergeTrees(root1->right, root2 ? root2->right : NULL);
        return root1;
    }
};