//Problem Statement
//You need to construct a string consists of parenthesis and integers from a binary tree with the preorder traversing way.
// The null node needs to be represented by empty parenthesis pair "()".And you need to omit all the empty parenthesis pairs that don't affect the one-to-one mapping relationship between the string and the original binary tree.

#include <bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
   public:
    string tree2str(TreeNode *t) {
        string ans = "";
        if (t) {
            ans += to_string(t->val);
            if (!t->left && t->right)
                ans += "()";
            ans += (t->left) ? "(" + tree2str(t->left) + ")" : "";
            ans += (t->right) ? "(" + tree2str(t->right) + ")" : "";
        }
        return ans;
    }
};