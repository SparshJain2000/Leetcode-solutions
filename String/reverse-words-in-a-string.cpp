//Problem Statement
/*
Given an input string, reverse the string word by word.

*/
#include <bits/stdc++.h>
class Solution
{
    string ltrim(string s)
    {
        s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {
                    return !isspace(ch);
                }));
        return s;
    }
    string rtrim(string s)
    {
        s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {
                    return !isspace(ch);
                }).base(),
                s.end());
        return s;
    }
    string trim(string s)
    {
        s = ltrim(s);
        s = rtrim(s);
        return s;
    }

public:
    string reverseWords(string s)
    {
        int j = 0;
        vector<string> v;
        s = trim(s);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                v.push_back(s.substr(j, i - j));
                while (i < s.length() && s[i] == ' ')
                    i++;
                i--;
                j = i + 1;
            }
        }
        v.push_back(s.substr(j, s.length() - j));
        string ans = "";
        for (string str : v)
        {
            ans = str + " " + ans;
        }
        return ans.substr(0, ans.length() - 1);
    }
};