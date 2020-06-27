//Problem Statement
/*
Given a positive integer n and you can do operations as follow:
1. If n is even, replace n with n/2.
2. If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?
*/
#include <bits/stdc++.h>
class Solution
{
public:
    bool util(int n)
    {
        int x = n + 1;
        int y = n - 1;
        if (x % y == 0)
            return false;
        while (x >= 0 && y >= 0)
        {
            x >>= 1;
            y >>= 1;
            if (x & 1)
                return false;
            if (y & 1)
                return true;
        }
        return true;
    }
    int integerReplacement(int n)
    {
        int c = 0;
        while (n != 1)
        {
            if (n == INT_MAX)
                n--;
            if (!(n & 1))
                n >>= 1;
            else if (util(n))
                n++;
            else
                n--;
            c++;
        }
        return c;
    }
};