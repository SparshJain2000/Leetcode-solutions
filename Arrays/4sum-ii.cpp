//Problem Statement
/*
Given a binary search tree, return a balanced binary search tree with the same node values.
A binary search tree is balanced if and only if the depth of the two subtrees of every node never differ by more than 1.
If there is more than one answer, return any of them.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> m;
        for (int i : A) {
            for (int j : B) {
                m[i + j]++;
            }
        }
        int ans = 0;
        for (int i : C) {
            for (int j : D) {
                ans += m[-i - j];
            }
        }
        return ans;
    }
};