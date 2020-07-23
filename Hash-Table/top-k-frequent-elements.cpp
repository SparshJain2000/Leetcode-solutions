//Problem Statement
/*
Given a non-empty array of integers, return the k most frequent elements.
*/
#include <bits/stdc++.h>
typedef pair<int, int> p;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> m;
        for (int i : nums)
        {
            if (!m[i])
            {
                m[i] = 1;
            }
            else
            {
                ++m[i];
            }
        }
        vector<p> v;
        copy(m.begin(), m.end(), back_inserter(v));
        sort(v.begin(), v.end(), [](const p &a, const p &b) {
            return (a.second > b.second);
        });
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(v[i].first);
        }
        return ans;
    }
};