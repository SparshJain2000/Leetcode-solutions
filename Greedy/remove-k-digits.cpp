//Problem Statement
/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        while (k > 0)
        {
            int n = num.size();
            int i = 0;
            while (i + 1 < n && num[i] <= num[i + 1])
                i++;
            num.erase(i, 1);
            k--;
        }
        // trim leading zeros
        int s = 0;
        while (s < (int)num.size() - 1 && num[s] == '0')
            s++;
        num.erase(0, s);

        return num == "" ? "0" : num;
    }
};