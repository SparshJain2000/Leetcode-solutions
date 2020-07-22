//Problem Statement
/*
We have a set of items: the i-th item has value values[i] and label labels[i].

Then, we choose a subset S of these items, such that:

|S| <= num_wanted
For every label L, the number of items in S with label L is <= use_limit.
Return the largest possible sum of the subset S.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int num_wanted, int use_limit)
    {
        vector<pair<int, int>> m;
        map<int, int> use;
        for (int i = 0; i < values.size(); i++)
        {
            m.push_back(pair<int, int>(values[i], labels[i]));
        }
        sort(m.begin(), m.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.first > b.first;
        });
        int ans = 0;
        for (pair<int, int> p : m)
        {
            if (use[p.second] < use_limit)
            {
                ans += p.first;
                use[p.second]++;
                num_wanted--;
            }
            if (!num_wanted)
                break;
        }
        return ans;
    }
};