//Problem Statement
/*
You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.
Return the number of servers that communicate with any other server.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
class Solution
{
public:
    int countServers(vector<vector<int>> &grid)
    {
        vi rsum;
        vi csum(grid[0].size(), 0);
        for (vi row : grid)
            rsum.push_back(accumulate(row.begin(), row.end(), 0));

        for (int i = 0; i < grid[0].size(); i++)
            for (int j = 0; j < grid.size(); j++)
                csum[i] += grid[j][i];

        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j])
                    if (rsum[i] > 1 || csum[j] > 1)
                        ans++;

        return ans;
    }
};