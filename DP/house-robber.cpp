//Problem Statement
/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        // f(0)=nums[0];
        // f(1)=max(nums[0],nums[1]);
        // f(i)=max(f(i-2)+nums[i],f(i-1));
        int f0 = 0, f1 = 0;
        if (nums.size() > 0)
            f0 = nums[0];
        if (nums.size() >= 2)
            f1 = max(f0, nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            int temp = f1;
            f1 = max(f0 + nums[i], f1);
            f0 = temp;
        }
        return max(f0, f1);
    }
};
