//Problem Statement
/*
Given a binary tree, find the leftmost value in the last row of the tree.
*/

#include <bits/stdc++.h>
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    int findBottomLeftValue(TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);
        vector<int> temp;

        while (!q.empty())
        {
            queue<TreeNode *> q1;
            temp.clear();
            while (!q.empty())
            {
                TreeNode *n = q.front();
                q.pop();
                temp.push_back(n->val);
                if (n->left)
                    q1.push(n->left);
                if (n->right)
                    q1.push(n->right);
            }
            q = q1;
        }
        return temp.front();
    }
};