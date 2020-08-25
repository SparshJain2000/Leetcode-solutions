//Problem Statement
/*
Given a non-negative integer num, return the number of steps to reduce it to zero. If the current number is even, you have to divide it by 2, otherwise, you have to subtract 1 from it.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int numberOfSteps(int num)
    {
        int count = 0;
        while (num != 0)
        {
            if (num & 1)
                num &= ~(1);
            else
                num >>= 1;
            count++;
        }
        return count;
    }
};