//Problem Statement
/*
Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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