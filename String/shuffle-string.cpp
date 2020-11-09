/*
Problem Statement
Given a string s and an integer array indices of the same length.

The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        string ans = "";
        map<int, char> m;
        for (int i = 0; i < indices.size(); i++)
            m[indices[i]] = s[i];
        for (auto x : m)
            ans += x.second;
        return ans;
    }
};