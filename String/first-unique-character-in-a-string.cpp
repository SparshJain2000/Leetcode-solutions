//Problem Statement
/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int firstUniqChar(string s)
    {
        short arr[26] = {0};
        for (char c : s)
            arr[c - 97]++;

        for (int i = 0; i < s.length(); i++)
            if (arr[s[i] - 97] == 1)
                return i;
        return -1;
    }
};