//Problem Statement
/*
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int c = 0;
            int k = 0;
            int cur_size = ans.size();
            while (i - c >= 0 && k + c < n)
                ans.push_back(matrix[k + c][i - c++]);
            if (!(i & 1)) reverse(ans.begin() + cur_size, ans.end());
        }
        for (int i = 1; i < n; i++) {
            int c = 0;
            int j = m - 1;
            int cur_size = ans.size();
            while (j - c >= 0 && i + c < n)
                ans.push_back(matrix[i + c][j - c++]);
            if ((m + i) & 1) reverse(ans.begin() + cur_size, ans.end());
        }
        return ans;
    }
};