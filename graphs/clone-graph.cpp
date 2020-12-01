//Problem Statement
/*
Given a reference of a node in a connected undirected graph.
Return a deep copy (clone) of the graph.
Each node in the graph contains a val (int) and a list (List[Node]) of its neighbors.
The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
*/
#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
    Node *cloneGraphUtil(Node *node, unordered_map<int, Node *> &m)
    {
        if (!node)
            return NULL;
        Node *newNode = new Node(node->val);
        m[node->val] = newNode;
        for (Node *n : node->neighbors)
            newNode->neighbors.push_back((m[n->val]) ? m[n->val] : cloneGraphUtil(n, m));
        return newNode;
    }

public:
    Node *cloneGraph(Node *node)
    {
        unordered_map<int, Node *> m;
        return cloneGraphUtil(node, m);
    }
};