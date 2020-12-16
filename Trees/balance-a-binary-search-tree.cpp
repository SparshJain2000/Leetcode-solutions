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
    void inorder(TreeNode *root, vector<int> &arr) {
        if (root) {
            inorder(root->left, arr);
            arr.push_back(root->val);
            inorder(root->right, arr);
        }
    }
    TreeNode *arrtobst(vector<int> arr) {
        if (!arr.size())
            return NULL;
        int mid = arr.size() / 2;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = arrtobst(vector<int>(arr.begin(), arr.begin() + mid));
        root->right = arrtobst(vector<int>(arr.begin() + mid + 1, arr.end()));
        return root;
    }

   public:
    TreeNode *balanceBST(TreeNode *root) {
        vector<int> arr;
        inorder(root, arr);
        return arrtobst(arr);
    }
};