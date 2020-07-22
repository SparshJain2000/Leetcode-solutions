//Problem Statement
/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        if (p == "")
            return ans;
        unordered_map<char, int> m;
        for (char c : p)
        {
            m[c]++;
        }
        int n = p.length();
        for (int i = 0; i < n; i++)
        {
            m[s[i]]--;
        }
        bool flag = true;
        for (pair<char, int> p : m)
        {
            if (p.second)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            ans.push_back(0);
        for (int i = n; i < s.length(); i++)
        {
            m[s[i - n]]++;
            m[s[i]]--;
            if (flag)
            {
                if (m[s[i]])
                    flag = false;
            }
            else
            {
                flag = true;
                for (pair<char, int> p : m)
                {
                    if (p.second)
                    {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag)
                ans.push_back(i - n + 1);
        }
        return ans;
    }
};