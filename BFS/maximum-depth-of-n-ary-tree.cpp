//Problem Statement
/*
Given a n-ary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value.
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
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int ans = 0;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            ans++;
            int n = q.size();
            while (n--)
            {
                for (Node *temp : q.front()->children)
                    q.push(temp);
                q.pop();
            }
        }
        return ans;
    }
};