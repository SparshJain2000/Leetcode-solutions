//Problem Statement
/*
    Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:
    The root is the maximum number in the array.
    The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
    The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
    Construct the maximum tree by the given array and output the root node of this tree.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{

public:
    TreeNode *constructMaximumBinaryTree(vi arr)
    {
        if (arr.size() == 0)
            return NULL;
        int mid = max_element(arr.begin(), arr.end()) - arr.begin();
        return new TreeNode(arr.at(mid), constructMaximumBinaryTree(vi(arr.begin(), arr.begin() + mid)), constructMaximumBinaryTree(vi(arr.begin() + 1 + mid, arr.end())));
    }
};