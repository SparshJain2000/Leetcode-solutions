//Problem Statement
/*Given an integer, write a function to determine if it is a power of two.*/
#include <bits/stdc++.h>
class Solution
{
public:
    int Bits(long long int n)
    {
        int c = 0;
        while (n)
        {
            n &= (n - 1);
            c++;
            if (c > 1)
                return false;
        }
        return true;
    }
    bool isPowerOfTwo(int n)
    {
        return n <= 0 ? false : Bits(n);
    }
};