//Problem Statement
/*
Given an integer n and an integer start.

Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.

Return the bitwise XOR of all elements of nums.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int ans = start;
        for (int i = 1; i < n; i++)
        {
            ans ^= (start + 2 * i);
        }
        return ans;
    }
};