//Problem Statement
/*
There are n cities numbered from 0 to n-1 and n-1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.
Roads are represented by connections where connections[i] = [a, b] represents a road from city a to b.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.
It's guaranteed that each city can reach the city 0 after reorder.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        unordered_map<int, vector<int>> m, m1;
        for (vector<int> v : connections)
        {
            m[v[0]].push_back(v[1]);
            m1[v[1]].push_back(v[0]);
        }
        queue<int> q;
        q.push(0);
        int ans = 0;
        vector<int> vis(n, 0);
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                int curr = q.front();
                q.pop();
                vis[curr] = 1;
                for (int i : m[curr])
                {
                    if (vis[i])
                        continue;
                    ans++;
                    q.push(i);
                }
                for (int i : m1[curr])
                    if (!vis[i])
                        q.push(i);
            }
        }
        return ans;
    }
};