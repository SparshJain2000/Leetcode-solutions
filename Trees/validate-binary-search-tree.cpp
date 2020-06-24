//Problem Statement -

// Given a binary tree, determine if it is a valid binary search tree(BST).
//Assume a BST is defined as follows :
//      The left subtree of a node contains only nodes with keys less than the node's key.
//      The right subtree of a node contains only nodes with keys greater than the node's key.
//      Both the left and right subtrees must also be binary search trees.
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    static bool valid(TreeNode *root, long long int min, long long int max)
    {
        if (root == NULL)
            return true;
        if (root->val < max && root->val > min && valid(root->left, min, root->val) && valid(root->right, root->val, max))
            return true;
        return false;
    }
    bool isValidBST(TreeNode *root)
    {
        long long int min = -pow(10, 18);
        long long int max = pow(10, 18) - 1;
        return valid(root, min, max);
    }
};