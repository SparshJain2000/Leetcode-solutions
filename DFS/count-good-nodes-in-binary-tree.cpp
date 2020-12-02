//Problem Statement
/*
Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
Return the number of good nodes in the binary tree.
*/
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
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
class Solution
{
    void util(TreeNode *root, int m, int &ans)
    {
        if (!root)
            return;
        if (m <= root->val)
        {
            ans++;
            m = root->val;
        }
        util(root->left, m, ans);
        util(root->right, m, ans);
    }

public:
    int goodNodes(TreeNode *root)
    {
        int m = INT_MIN;
        int ans = 0;
        util(root, m, ans);
        return ans;
    }
};