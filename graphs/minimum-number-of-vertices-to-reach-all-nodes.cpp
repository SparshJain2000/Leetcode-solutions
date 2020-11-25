//Problem Statement
/*
Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents a directed edge from node fromi to node toi.

Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.

Notice that you can return the vertices in any order.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
class Solution
{
public:
    vi findSmallestSetOfVertices(int n, vii &edges)
    {
        vi ans;
        vi indeg(n, 0);
        for (vi v : edges)
            indeg[v[1]]++;
        for (int i = 0; i < n; i++)
            if (!indeg[i])
                ans.push_back(i);
        return ans;
    }
};