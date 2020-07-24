//Problem Statement
/*
Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        n = n ^ (n >> 1);
        n = n & (n - 1);
        return (n & 1) == 0;
    }
};