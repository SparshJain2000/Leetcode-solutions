//Problem Statement
/*
Given a string, sort it in decreasing order based on the frequency of characters.
*/
#include <bits/stdc++.h>
typedef pair<char, int> pairs;
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> m;
        for (char i : s)
            m[i]++;
        vector<pairs> v;
        for (pair i : m)
            v.push_back(i);
        sort(v.begin(), v.end(), [](const pairs &a, const pairs &b) {
            return (a.second >= b.second);
        });
        string ans;
        for (pairs i : v)
            ans += string(i.second, i.first);
        return ans;
    }
};