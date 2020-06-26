//Problem Statement
/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice.Find the two elements that appear only once.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    vector<int>
    singleNumber(vector<int> &nums)
    {
        int num = 0;
        for (int i : nums)
            num ^= i;
        num &= (-num);
        int a = 0;
        int b = 0;
        for (int j : nums)
        {
            if (j & num)
                a ^= j;
            else
                b ^= j;
        }
        vector<int> ans({(int)a, (int)b});
        return ans;
    }
};