//Problem Statement
/*
Given a binary tree, return the sum of values of its deepest leaves.
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

    TreeNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val, TreeNode *_left, TreeNode *_right, TreeNode *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution
{
    int maxHeight(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = maxHeight(root->left);
        int r = maxHeight(root->right);
        return (l > r) ? l + 1 : r + 1;
    }
    int util(TreeNode *root, int maxHeight, int curr)
    {
        if (!root)
            return 0;
        return (curr == maxHeight) ? root->val : util(root->left, maxHeight, curr + 1) + util(root->right, maxHeight, curr + 1);
    }

public:
    int deepestLeavesSum(TreeNode *root)
    {
        //* DFS : First find maxDepth and then find sum of nodes at that depth
        // int curr=1;
        // return util(root, maxHeight(root), curr);
        //* BFS : level order traversal and return sum of elements at last level
        queue<TreeNode *> q;
        vector<int> temp;
        q.push(root);
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
        return accumulate(temp.begin(), temp.end(), 0);
    }
};