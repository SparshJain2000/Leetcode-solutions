//Problem Statement
/*
Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to n. The fractions can be in any order.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    int gcd(int a, int b)
    {
        return b ? gcd(b, a % b) : a;
    }

public:
    vector<string> simplifiedFractions(int n)
    {
        vector<string> ans;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (gcd(i, j) == 1)
                    ans.push_back(to_string(j) + "/" + to_string(i));
            }
        }
        return ans;
    }
};