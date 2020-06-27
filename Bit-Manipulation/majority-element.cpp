//Problem Statement
/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size() / 2;
        sort(nums.begin(), nums.end());
        int ans = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (ans > n)
                return nums[i];
            if (nums[i] == nums[i + 1])
                ans++;
            else
                ans = 1;
        }
        return 0;
    }
};