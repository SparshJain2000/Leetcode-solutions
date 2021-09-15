/*
Problem Statement
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(1, vector<int>(1, 1));
        if (numRows > 1) ans.push_back({1, 1});
        for (int i = 2; i < numRows; i++) {
            vector<int> temp(i + 1, 1);
            ans.push_back(temp);
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
        return ans;
    }
};