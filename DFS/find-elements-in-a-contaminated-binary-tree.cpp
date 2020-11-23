//Problem Statement
/*
Given a binary tree with the following rules:

root.val == 0
If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

You need to first recover the binary tree and then implement the FindElements class:

FindElements(TreeNode* root) Initializes the object with a contamined binary tree, you need to recover it first.
bool find(int target) Return if the target value exists in the recovered binary tree.
*/
#include <bits/stdc++.h>
using namespace std;
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
class FindElements
{
    unordered_map<int, int> m;
    void dfs(TreeNode *root)
    {
        if (root)
        {
            int l = (2 * root->val) + 1;
            if (root->left)
                root->left->val = l, dfs(root->left), m[l]++;
            if (root->right)
                root->right->val = l + 1, dfs(root->right), m[l + 1]++;
        }
    }

public:
    FindElements(TreeNode *root)
    {
        m = unordered_map<int, int>();
        root->val = 0;
        dfs(root);
    }

    bool find(int target)
    {
        return m[target];
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */