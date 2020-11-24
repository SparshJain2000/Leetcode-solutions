//Problem Statement
/*
Given a binary tree, return the sum of values of nodes with even-valued grandparent.  (A grandparent of a node is the parent of its parent, if it exists.)

If there are no nodes with an even-valued grandparent, return 0.
*/
#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}
};
class Solution
{
    void util(TreeNode *root, int &ans)
    {
        if (root)
        {
            if (!(root->val % 2))
            {
                if (root->left && root->left->left)
                    ans += root->left->left->val;
                if (root->left && root->left->right)
                    ans += root->left->right->val;
                if (root->right && root->right->left)
                    ans += root->right->left->val;
                if (root->right && root->right->right)
                    ans += root->right->right->val;
            }
            util(root->left, ans);
            util(root->right, ans);
        }
    }

public:
    int sumEvenGrandparent(TreeNode *root)
    {
        int ans = 0;
        util(root, ans);
        return ans;
    }
};