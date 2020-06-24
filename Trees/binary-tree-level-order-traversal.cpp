//Problem Statement
//Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> temp;
            queue<TreeNode *> q1;
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
            ans.push_back(temp);
        }
        return ans;
    }
};