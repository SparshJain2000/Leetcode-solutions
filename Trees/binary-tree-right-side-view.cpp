//Problem Statement
/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> arr;
        if (root == NULL)
            return arr;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            queue<TreeNode *> q1;
            int i = q.size() - 1;

            while (!q.empty())
            {
                TreeNode *n = q.front();
                q.pop();
                if (i == 0)
                {
                    arr.push_back(n->val);
                    i = -1;
                }
                else
                    i--;
                if (n->left)
                    q1.push(n->left);
                if (n->right)
                    q1.push(n->right);
            }
            q = q1;
        }
        return arr;
    }
};