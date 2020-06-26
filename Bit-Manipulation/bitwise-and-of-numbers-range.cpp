//Problem Statement
//Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
#include <bits/stdc++.h>
class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {

        while (m < n)
        {
            n = n & (n - 1);
        }
        return n;
    }
};