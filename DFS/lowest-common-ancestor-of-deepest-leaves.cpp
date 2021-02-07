//Problem Statement
/*
Given a binary tree, return the sum of values of its deepest leaves.
*/
#include <bits/stdc++.h>
using namespace std;
// Definition for a Node.
class TreeNode {
   public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* next;

    TreeNode() : val(0), left(NULL), right(NULL), next(NULL) {}

    TreeNode(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
    unordered_map<TreeNode*, int> m;
    void dfs(TreeNode* root, TreeNode* parent) {
        if (root) {
            m[root] = m[parent] + 1;
            dfs(root->left, root);
            dfs(root->right, root);
        }
    }
    TreeNode* answer(TreeNode* root, int max_depth) {
        if (!root || m[root] == max_depth) return root;
        TreeNode* l = answer(root->left, max_depth);
        TreeNode* r = answer(root->right, max_depth);
        if (l && r) return root;
        if (l) return l;
        if (r) return r;
        return NULL;
    }

   public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        unordered_map<TreeNode*, int> m1;
        this->m = m1;
        m[NULL] = -1;
        int max_depth = -1;
        dfs(root, NULL);
        for (auto x : m) max_depth = max(max_depth, x.second);
        return answer(root, max_depth);
    }
};