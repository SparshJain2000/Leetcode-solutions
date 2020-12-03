//Problem Statement
/*
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<char> vc;
typedef vector<vc> vcc;
class Solution
{
    // vector<int>dir{1,0,-1,0,1};
    void fill(vcc &grid, int i, int j)
    {
        if (i >= 0 && j >= 0 && i < grid.size() && j < grid[0].size() && grid[i][j] == '1')
        {
            grid[i][j] = '0';
            // for(int k=0;k<dir.size()-1;k++) fill(grid,i+dir[k],j+dir[k+1]);
            fill(grid, i + 1, j);
            fill(grid, i - 1, j);
            fill(grid, i, j + 1);
            fill(grid, i, j - 1);
        }
    }

public:
    int numIslands(vcc &grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j] == '1')
                    fill(grid, i, j), ans++;
        return ans;
    }
};