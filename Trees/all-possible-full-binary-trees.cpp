//Problem Statement
/*
Given a binary search tree, return a balanced binary search tree with the same node values.
A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.
If there is more than one answer, return any of them.
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
   private:
    unordered_map<int, vector<TreeNode *>> memo;

   public:
    vector<TreeNode *> allPossibleFBT(int N) {
        if (memo.find(N) == memo.end()) {
            vector<TreeNode *> vec;
            if (N == 1)
                vec.push_back(new TreeNode(0));
            else if (N % 2) {
                for (int i = 0; i < N; ++i)
                    for (TreeNode *left : allPossibleFBT(i))
                        for (TreeNode *right : allPossibleFBT(N - i - 1))
                            vec.push_back(new TreeNode(0, left, right));
            }
            memo[N] = vec;
        }
        return memo[N];
    }
};