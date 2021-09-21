//Problem Statement
/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as 1 and 0 respectively in the grid.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 1));
        int i = 0;
        for (; i < n; i++)
            if (grid[i][0] == 1) break;
        for (; i < n; i++) dp[i][0] = 0;

        i = 0;
        for (; i < m; i++)
            if (grid[0][i] == 1) break;
        for (; i < m; i++) dp[0][i] = 0;

        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                dp[i][j] = (grid[i][j] == 1) ? 0 : dp[i - 1][j] + dp[i][j - 1];

        return dp[n - 1][m - 1];
    }
};