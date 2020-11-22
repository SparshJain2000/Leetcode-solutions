//Problem Statement
/*
Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1, and return them in any order.

The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
class Solution
{
    void dfs(vii graph, int n, vi &path, vii &ans)
    {
        if (n == graph.size() - 1)
        {
            ans.push_back(path);
            return;
        }
        for (int i : graph[n])
        {
            path.push_back(i);
            dfs(graph, i, path, ans);
            path.pop_back();
        }
    }

public:
    vii allPathsSourceTarget(vii &graph)
    {
        vi path;
        vii ans;
        path.push_back(0);
        dfs(graph, 0, path, ans);
        return ans;
    }
};