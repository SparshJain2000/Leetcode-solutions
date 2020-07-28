//Problem Statement

/*

    Given a binary tree, return the sum of values of its deepest leaves.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    int sum = 0, l = 0, max = 0;
    vector<int> v;

    void find(TreeNode *root)
    {
        if (root == NULL)
            return;

        l++;
        if (root->left)
            find(root->left);
        if (root->right)
            find(root->right);

        if (root->left == NULL && root->right == NULL)
        {
            if (l > max)
            {
                cout << l << endl;
                max = l;
                v.clear();
                v.push_back(root->val);
            }
            else if (l == max)
                v.push_back(root->val);
        }

        l--;
    }

    int deepestLeavesSum(TreeNode *root)
    {

        find(root);

        for (int i = 0; i < v.size(); i++)
        {
            sum += v.at(i);
        }

        return sum;
    }
};