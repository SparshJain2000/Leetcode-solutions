//Problem Statement
/*
Given an n-ary tree, return the level order traversal of its nodes' values.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).
*/
#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            while (n--)
            {
                Node *node = q.front();
                temp.push_back(node->val);
                q.pop();
                for (Node *x : node->children)
                    q.push(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};