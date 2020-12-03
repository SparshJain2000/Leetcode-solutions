
//Problem Statement
/*
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    vector<string> findItinerary(vector<vector<string>> tickets)
    {
        unordered_map<string, multiset<string>> m;
        vector<string> ans;
        if (tickets.size() == 0)
            return ans;
        for (auto p : tickets)
            m[p[0]].insert(p[1]);
        stack<string> dfs;
        dfs.push("JFK");
        while (!dfs.empty())
        {
            string top = dfs.top();
            if (m[top].empty())
            {
                ans.push_back(top);
                dfs.pop();
            }
            else
            {
                dfs.push(*(m[top].begin()));
                m[top].erase(m[top].begin());
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};