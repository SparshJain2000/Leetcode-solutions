//Problem Statement
/*
Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int a = 0, b = 0;
        // 1 0 0 => 1 0
        // 0 1 1 => 1 0

        //0 1 0 => 0 1
        //0 0 1 => 0 1
        for (int c : nums)
        {
            int z = (~a) & b & c | a & (~b) & (~c);
            b = (~a) & b & (~c) | (~a) & (~b) & c;
            a = z;
        }
        return a | b;
    }
};