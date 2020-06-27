//Problem Statement
/*
Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.
*/
#include <bits/stdc++.h>

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        if (!((a | b) ^ c))
            return 0;
        int ans = 0;
        while (c || (a | b))
        {
            int m = a & 1;
            int n = b & 1;
            int o = c & 1;
            if ((m | n) ^ o)
            {
                if (!o)
                {
                    if (m)
                        ans++;
                    if (n)
                        ans++;
                }
                else
                    ans++;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        return ans;
    }
};