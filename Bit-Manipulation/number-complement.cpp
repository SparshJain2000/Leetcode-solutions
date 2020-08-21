//Problem Statement
/*
Given a positive integer num, output its complement number. The complement strategy is to flip the bits of its binary representation.
*/
#include <bits/stdc++.h>
class Solution
{
private:
    int mask(int num)
    {
        int m = 0;
        int n = 0;
        while (num)
        {
            num >>= 1;
            m |= 1 << n;
            n++;
        }
        return m;
    }

public:
    int findComplement(int num)
    {
        return num ^ mask(num);
    }
};
