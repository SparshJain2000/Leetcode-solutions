//Problem Statement
/*
Given a 32-bit signed integer, reverse digits of an integer.
Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void reverseStr(string &str)
    {
        int n = str.length();
        for (int i = 0; i < n / 2; i++)
            swap(str[i], str[n - i - 1]);
    }
    int reverse(int x)
    {
        string ans = to_string(x);
        if (ans[0] == '-')
        {
            ans = ans.substr(1, ans.length());
            reverseStr(ans);
            int x;
            try
            {
                x = stoi(ans);
            }
            catch (exception e)
            {
                return 0;
            }
            x = x * (-1);
            return x;
        }
        int w;
        reverseStr(ans);
        try
        {
            w = stoi(ans);
        }
        catch (exception e)
        {
            return 0;
        }
        return w;
    }
};