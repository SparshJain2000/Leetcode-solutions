//Problem Statement
/*
Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
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

public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n1 = num1.length();
        int n2 = num2.length();
        string mul = "";
        for (int i = n2 - 1; i >= 0; i--)
        {
            char m = num2[i];
            int carry = 0;
            string ans = "";
            for (int j = n1 - 1; j >= 0; j--)
            {
                char n = num1[j];
                int x = (m - (int)'0') * (n - (int)'0') + carry;
                ans = (char)(x % 10 + (int)'0') + ans;
                carry = x / 10;
            }
            if (carry)
                ans = char(carry + (int)'0') + ans;
            ans = ans + string(n2 - 1 - i, '0');
            mul = addStrings(ans, mul);
        }
        return mul;
    }
};