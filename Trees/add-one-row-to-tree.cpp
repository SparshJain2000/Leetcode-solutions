//Problem Statement
/*
Given the root of a binary tree, then value v and depth d, you need to add a row of nodes with value v at the given depth d. The root node is at depth 1.
The adding rule is: given a positive integer depth d, for each NOT null tree nodes N in depth d-1, create two tree nodes with value v as N's left subtree root and right subtree root. And N's original left subtree should be the left subtree of the new left subtree root, its original right subtree should be the right subtree of the new right subtree root. If depth d is 1 that means there is no depth d-1 at all, then create a tree node with value v as the new root of the whole original tree, and the original tree is the new root's left subtree.
*/

#include <bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
   public:
    TreeNode *addOneRow(TreeNode *root, int v, int d) {
        queue<TreeNode *> q;
        int depth = 1;
        q.push(root);
        if (d == 1)
            root = new TreeNode(v, root, NULL);

        while (!q.empty()) {
            if (depth == d - 1)
                while (!q.empty()) {
                    TreeNode *node = q.front();
                    q.pop();
                    node->left = new TreeNode(v, node->left, NULL);
                    node->right = new TreeNode(v, NULL, node->right);
                }
            queue<TreeNode *> q1;
            while (!q.empty()) {
                TreeNode *n = q.front();
                q.pop();
                if (n->left)
                    q1.push(n->left);
                if (n->right)
                    q1.push(n->right);
            }
            q = q1;
            depth++;
        }
        return root;
    }
};