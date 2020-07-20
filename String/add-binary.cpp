//Problem Statement
/*Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string z = string(abs(int(a.length() - b.length())), '0');
        (a.length() > b.length()) ? b = z + b : a = z + a;
        int res = 0;
        string ans = "";
        for (int i = a.length() - 1; i >= 0; i--)
        {
            int sum = res + (a[i] == '0' ? 0 : 1) + (b[i] == '0' ? 0 : 1);
            res = (sum == 2 || sum == 3) ? 1 : 0;
            ans = ((sum == 1 || sum == 3) ? '1' : '0') + ans;
        }
        if (res)
            ans = '1' + ans;
        return ans;
    }
};