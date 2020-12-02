//Problem Statement
/*
There is an infrastructure of n cities with some number of roads connecting these cities. Each roads[i] = [ai, bi] indicates that there is a bidirectional road between cities ai and bi.
The network rank of two different cities is defined as the total number of directly connected roads to either city. If a road is directly connected to both cities, it is only counted once.
The maximal network rank of the infrastructure is the maximum network rank of all pairs of different cities.
Given the integer n and the array roads, return the maximal network rank of the entire infrastructure.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class Solution
{
public:
    int maximalNetworkRank(int n, vector<vi> &roads)
    {
        unordered_map<int, vi> m;
        for (vi v : roads)
        {
            m[v[0]].push_back(v[1]);
            m[v[1]].push_back(v[0]);
        }
        vi vec(n, 0);
        for (int i = 0; i < n; i++)
            vec[i] = i;
        sort(
            vec.begin(), vec.end(), [&m](const int &a, const int &b) {
                return m[a].size() > m[b].size();
            });
        int ans = INT_MIN;
        for (auto i = vec.begin(); i != vec.end(); i++)
            for (auto j = i + 1; j != vec.end(); j++)
            {
                int temp = 0;
                bool flag = false;
                for (int k : m[*i])
                    if (k == *j)
                    {
                        flag = true;
                        break;
                    }
                temp += m[*i].size() + m[*j].size();
                if (flag)
                    temp--;
                ans = max(temp, ans);
                if (ans != temp)
                    return ans;
            }
        return ans;
    }
};
