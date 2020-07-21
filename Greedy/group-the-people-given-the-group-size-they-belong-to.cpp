//Problem Statement
/*
There are n people whose IDs go from 0 to n - 1 and each person belongs exactly to one group. Given the array groupSizes of length n telling the group size each person belongs to, return the groups there are and the people's IDs each group includes.

You can return any solution in any order and the same applies for IDs. Also, it is guaranteed that there exists at least one solution. 

*/
#include <bits/stdc++.h>
class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        vector<vector<int>> ans;
        map<int, vector<int>> m;
        for (int i = 0; i < groupSizes.size(); i++)
        {
            m[groupSizes[i]].push_back(i);
        }
        for (pair<int, vector<int>> x : m)
        {
            vector<int> t = x.second;
            int n = x.first;
            if ((n == t.size()))
                ans.push_back(t);
            else
            {
                for (int i = 0; i < t.size() / n; i++)
                    ans.push_back(vector<int>(t.begin() + (n * i), t.begin() + (n * (i + 1))));
            }
        }
        return ans;
    }
};