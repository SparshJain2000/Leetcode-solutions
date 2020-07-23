//Problem Statement
/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        if (!nums.size())
            return 0;
        int ans = 0;
        map<int, int> m;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum == k)
                ans++;
            ans += m[sum - k];
            m[sum]++;
        }
        return ans;
    }
};