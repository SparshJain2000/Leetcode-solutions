//Problem Statement
/*
Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    string addStrings(string a, string b)
    {
        int m = a.length();
        int n = b.length();
        string z = string(abs(m - n), '0');
        (m < n) ? (a = z + a) : (b = z + b);
        int res = 0;
        string ans = "";
        for (int i = 0; i < max(m, n); i++)
        {
            int x = a[a.length() - i - 1] + b[b.length() - i - 1] - 2 * (int)'0' + res;
            ans = (char)(x % 10 + (int)'0') + ans;
            res = x / 10;
        }
        if (res)
            ans = "1" + ans;
        return ans;
    }
};