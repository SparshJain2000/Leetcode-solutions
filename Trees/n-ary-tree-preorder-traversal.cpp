//Problem Statement
/*
Given an n-ary tree, return the preorder traversal of its nodes' values.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value  .
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
    void pre(Node *root, vector<int> &v)
    {
        if (root)
        {
            v.push_back(root->val);
            for (auto node : root->children)
                pre(node, v);
        }
    }

public:
    vector<int> preorder(Node *root)
    {
        vector<int> v;
        pre(root, v);
        return v;
    }
};