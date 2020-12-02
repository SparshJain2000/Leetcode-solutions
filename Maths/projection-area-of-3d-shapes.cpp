//Problem Statement
/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int projectionArea(vector<vector<int>> &grid)
    {
        int xy = 0, yz = 0, xz = 0;
        for (vector<int> v : grid)
            xy += *max_element(v.begin(), v.end());

        for (int j = 0; j < grid[0].size(); j++)
        {
            int m = 0;
            for (int i = 0; i < grid.size(); i++)
            {
                m = max(m, grid[i][j]);
                if (grid[i][j])
                    xz += 1;
            }
            yz += m;
        }
        return xy + yz + xz;
    }
};