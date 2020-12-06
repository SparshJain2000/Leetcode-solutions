//Problem Statement
/*
Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
    1 which means a street connecting the left cell and the right cell.
    2 which means a street connecting the upper cell and the lower cell.
    3 which means a street connecting the left cell and the lower cell.
    4 which means a street connecting the right cell and the lower cell.
    5 which means a street connecting the left cell and the upper cell.
    6 which means a street connecting the right cell and the upper cell.
You will initially start at the street of the upper-left cell (0,0). A valid path in the grid is a path which starts from the upper left cell (0,0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.
Notice that you are not allowed to change any street.
Return true if there is a valid path in the grid or false otherwise.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vi> vii;
class Solution
{
    vector<int> dir{-1, 0, 1, 0, -1};

public:
    //by scaling grid
    bool hasValidPath(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vii graph(grid.size() * 3, vi(grid[0].size() * 3, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x = i * 3, y = j * 3;
                int temp = grid[i][j];
                graph[x + 1][y + 1] = 1;
                graph[x][y + 1] = temp == 2 || temp == 5 || temp == 6;
                graph[x + 1][y] = temp == 1 || temp == 5 || temp == 3;
                graph[x + 1][y + 2] = temp == 1 || temp == 4 || temp == 6;
                graph[x + 2][y + 1] = temp == 2 || temp == 3 || temp == 4;
            }
        }
        stack<pi> s;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (graph[i][j])
                {
                    s.push(pi(i, j));
                    break;
                }
        s.push(pi(0, 0));
        while (!s.empty())
        {
            int x = s.top().first;
            int y = s.top().second;
            s.pop();
            graph[x][y] = -1;
            if (x >= (m - 1) * 3 && y >= (n - 1) * 3)
                return true;
            for (int i = 0; i < dir.size() - 1; i++)
            {
                int x1 = x + dir[i];
                int y1 = y + dir[i + 1];
                if (x1 >= 0 && y1 >= 0 && x1 < m * 3 && y1 < n * 3 && graph[x1][y1] == 1)
                    s.push(pi(x1, y1));
            }
        }
        return false;
    }

    //by defining custom directions
    bool hasValidPath(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vii valDir;
        valDir.push_back(vi({0, 0, 0, 0}));
        valDir.push_back(vi({0, 1, 0, 1}));
        valDir.push_back(vi({1, 0, 1, 0}));
        valDir.push_back(vi({0, 0, 1, 1}));
        valDir.push_back(vi({0, 1, 1, 0}));
        valDir.push_back(vi({1, 0, 0, 1}));
        valDir.push_back(vi({1, 1, 0, 0}));

        stack<pi> s;
        s.push(pi(0, 0));
        while (!s.empty())
        {
            int x = s.top().first;
            int y = s.top().second;
            s.pop();
            int val = grid[x][y];
            if (val != -1)
            {
                grid[x][y] = -1;
                if (x >= m - 1 && y >= n - 1)
                    return true;

                for (int i = 0; i < dir.size() - 1; i++)
                {
                    if (valDir[val][i] == 1)
                    {
                        int x1 = x + dir[i];
                        int y1 = y + dir[i + 1];
                        if (x1 >= 0 && y1 >= 0 && x1 < m && y1 < n && grid[x1][y1] != -1 && valDir[grid[x1][y1]][(i + 2) % 4] == 1)
                            s.push(pi(x1, y1));
                    }
                }
            }
        }
        return false;
    }
};
