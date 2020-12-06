//Problem Statement
/*
    There are n computers numbered from 0 to n-1 connected by ethernet cables connections forming a network where connections[i] = [a, b] represents a connection between computers a and b. Any computer can reach any other computer directly or indirectly through the network.
    Given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected. Return the minimum number of times you need to do this in order to make all the computers connected. If it's not possible, return -1. 
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class Solution
{
    void dfs(unordered_map<int, vi> &m, int s, vi &vis)
    {
        if (vis[s])
            return;
        vis[s] = 1;
        for (int i : m[s])
            if (!vis[i])
                dfs(m, i, vis);
    }

public:
    int makeConnected(int n, vector<vi> &connections)
    {
        if (n > connections.size() + 1)
            return -1;
        unordered_map<int, vi> m;
        for (vi v : connections)
        {
            m[v[0]].push_back(v[1]);
            m[v[1]].push_back(v[0]);
        }

        int ans = -1;
        vi vis(n, 0);
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs(m, i, vis), ans++;

        return ans;
    }
};