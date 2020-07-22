//Problem Statement
/*
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> ans = nums;
        sort(ans.begin(), ans.end());
        unordered_map<int, int> m;
        for (int i = ans.size() - 1; i >= 0; i--)
            m[ans[i]] = i;
        for (int i = 0; i < nums.size(); i++)
            nums[i] = m[nums[i]];
        return nums;
    }
};