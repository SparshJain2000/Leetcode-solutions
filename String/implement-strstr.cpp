//Problem Statement
/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int strStr(string str, string sub)
    {
        if (str == sub)
            return 0;
        int l = sub.length();
        if (l > str.length())
            return -1;
        for (int i = 0; i <= str.length() - l; i++)
        {
            if (str.substr(i, l) == sub)
                return i;
        }
        return -1;
    }
};