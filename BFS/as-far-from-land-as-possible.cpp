//Problem Statement
/*
    Given an n x n grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return -1.
    The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> p;

class Solution {
   public:
    int maxDistance(vector<vector<int>> &g, int steps = 0) {
        queue<p> q, q1;
        for (auto i = 0; i < g.size(); ++i)
            for (auto j = 0; j < g[i].size(); ++j)
                if (g[i][j] == 1)
                    q.push({i - 1, j}), q.push({i + 1, j}), q.push({i, j - 1}), q.push({i, j + 1});
        while (!q.empty()) {
            ++steps;
            int n = q.size();
            while (n--) {
                int i = q.front().first, j = q.front().second;
                q.pop();
                if (i >= 0 && j >= 0 && i < g.size() && j < g[i].size() && g[i][j] == 0) {
                    g[i][j] = steps;
                    q.push({i - 1, j}), q.push({i + 1, j}), q.push({i, j - 1}), q.push({i, j + 1});
                }
            }
        }
        return steps == 1 ? -1 : steps - 1;
    }
};