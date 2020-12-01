//Problem Statement
/*
Given the root of a binary tree, each node in the tree has a distinct value.
After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).
Return the roots of the trees in the remaining forest.  You may return the result in any order.
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
class Solution
{
    void Delete(TreeNode *root, int x, vector<TreeNode *> &ans)
    {
        if (root)
        {
            if (root->val == x)
            {
                if (root->left)
                    ans.push_back(root->left);
                if (root->right)
                    ans.push_back(root->right);
                for (int i = 0; i < ans.size(); i++)
                    if (ans[i] == root)
                    {
                        ans.erase(ans.begin() + i);
                        break;
                    }
                root = NULL;
                return;
            }
            if (root->left && root->left->val == x)
            {
                if (root->left->left)
                    ans.push_back(root->left->left);
                if (root->left->right)
                    ans.push_back(root->left->right);
                root->left = NULL;
                return;
            }
            if (root->right && root->right->val == x)
            {
                if (root->right->left)
                    ans.push_back(root->right->left);
                if (root->right->right)
                    ans.push_back(root->right->right);
                root->right = NULL;
                return;
            }
            Delete(root->left, x, ans);
            Delete(root->right, x, ans);
        }
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> ans;
        vector<TreeNode *> temp;
        ans.push_back(root);
        for (int i : to_delete)
        {
            temp = ans;
            for (TreeNode *r : ans)
                Delete(r, i, temp);
            ans = temp;
        }
        return ans;
    }
};
