//Problem Statement
/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
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
public:
    int maxLevelSum(TreeNode *root)
    {
        if (!root)
            return 0;
        int level = 0;
        int ans = level;
        int sum = INT_MIN;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            int currSum = 0;
            while (n--)
            {
                TreeNode *node = q.front();
                currSum += node->val;
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            level++;
            if (currSum > sum)
                sum = currSum, ans = level;
        }
        return ans;
    }
};
