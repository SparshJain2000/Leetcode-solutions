//Problem Statement
/*
    In a given grid, each cell can have one of three values:

    the value 0 representing an empty cell;
    the value 1 representing a fresh orange;
    the value 2 representing a rotten orange.
    
    Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.
    Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
class Solution
{
    vector<int> dir{1, 0, -1, 0, 1};

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (!grid.size())
            return 0;
        queue<pi> q;
        int fresh = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                    q.push(pi(i, j));
                else if (grid[i][j] == 1)
                    fresh++;
            }

        int ans = 0;
        if (!fresh)
            return 0;
        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                auto p = q.front();
                q.pop();
                for (int i = 0; i < dir.size() - 1; i++)
                {
                    int x = p.first + dir[i];
                    int y = p.second + dir[i + 1];
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1)
                        grid[x][y] = 2, fresh--, q.push(pi(x, y));
                }
            }
            ans++;
            if (!fresh)
                return ans;
        }
        return fresh ? -1 : ans;
    }
};