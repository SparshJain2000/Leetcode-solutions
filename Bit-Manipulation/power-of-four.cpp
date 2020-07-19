//Problem Statement
/*Given an integer (signed 32 bits), write a function to check whether it is a power of 4.*/
#include <bits/stdc++.h>
class Solution
{
public:
    bool isPowerOfFour(int num)
    {
        if (num <= 0)
            return false;
        if (num & (num - 1))
            return false;
        return ((0x55555555) & num) != 0;
    }
};