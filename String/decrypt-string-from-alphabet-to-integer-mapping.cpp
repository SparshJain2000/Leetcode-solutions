//Problem Statement
/*
Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.
*/
#include <bits/stdc++.h>

class Solution
{
public:
    string freqAlphabets(string s)
    {
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] - (int)'0' > 2)
                ans += s[i] - (int)'0' + (int)'a' - 1;
            else if (i + 2 < s.length())
            {
                if (s[i + 2] == '#')
                {
                    string x;
                    x += (char)s[i];
                    x += (char)s[i + 1];
                    ans += char(stoi(x) + (int)'a' - 1);
                    i += 2;
                }
                else
                    ans += s[i] - (int)'0' + (int)'a' - 1;
            }
            else
                ans += s[i] - (int)'0' + (int)'a' - 1;
        }
        return ans;
    }
};