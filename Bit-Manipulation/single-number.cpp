//Problem Statement
/*
Given a non-empty array of integers, every element appears twice except for one. Find that single one.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums.at(0);
        for (int i = 1; i < nums.size(); i++)
        {
            nums.at(i) = nums.at(i) ^ nums.at(i - 1);
        }
        return nums.at(nums.size() - 1);
    }
};