//Problem Statement
/*Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).*/
#include <bits/stdc++.h>
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int c = 0;
        while (n)
        {
            n &= (n - 1);
            c++;
        }
        return c;
    }
};