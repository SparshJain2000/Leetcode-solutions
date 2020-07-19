//Problem Statement
/*Reverse bits of a given 32 bits unsigned integer.*/
#include <bits/stdc++.h>
class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t x = 0;
        int i = 32;
        while (i--)
        {
            x = (x << 1) + (n & 1);
            n >>= 1;
        }
        return x;
    }
};