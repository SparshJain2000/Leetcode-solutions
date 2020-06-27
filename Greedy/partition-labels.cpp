//Problem Statement
/*
A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    vector<int> partitionLabels(string S)
    {
        vector<int> ans;
        if (!S.length())
            return ans;
        vector<int> m;
        for (int i = 0; i < 26; i++)
            m.push_back(0);
        for (int i = 0; i < S.length(); i++)
        {
            m[(int)S[i] - (int)'a'] = i;
        }
        for (int i = 0; i < S.length(); i++)
        {
            int last = m[(int)S[i] - (int)'a'];
            int j = i + 1;
            while (j <= last)
            {
                last = max(last, m[(int)S[j++] - (int)'a']);
            }
            ans.push_back(last - i + 1);
            i = last;
        }
        return ans;
    }
};