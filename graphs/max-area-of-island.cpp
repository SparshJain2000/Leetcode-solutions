//Problem Statement
/*
Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

class Solution
{
    vii grid;
    vii vis;
    int area(int r, int c)
    {
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || vis[r][c] == 1 || grid[r][c] == 0)
            return 0;
        vis[r][c] = 1;
        return 1 + area(r + 1, c) + area(r, c + 1) + area(r, c - 1) + area(r - 1, c);
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        this->grid = grid;
        this->vis = vii(grid.size(), vi(grid[0].size(), 0));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                ans = max(ans, area(i, j));
        return ans;
    }
};