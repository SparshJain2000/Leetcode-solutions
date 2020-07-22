//Problem Statement
/*Given a binary tree, flatten it to a linked list in-place*/

#include <bits/stdc++.h>
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        TreeNode *temp = root;
        while (temp)
        {
            if (temp->left)
            {
                TreeNode *ptr = temp->left;
                while (ptr->right)
                    ptr = ptr->right;
                ptr->right = temp->right;
                temp->right = temp->left;
                temp->left = NULL;
            }
            temp = temp->right;
        }
    }
};