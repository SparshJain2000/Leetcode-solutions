//Problem Statement
//Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
#include <bits/stdc++.h>

//  Definition for a binary tree node.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {

        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        int i = 0;
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
            if (i % 2 != 0)
                reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            i++;
        }
        return ans;
    }
};