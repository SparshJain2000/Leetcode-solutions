//Problem Statement
/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each elementin the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int p = 0;
        int j = 0;
        for (int i = 0; i <= p; i++)
        {
            j++;
            if (i >= n - 1)
                return true;
            p = max(p, nums[i] + i);
        }
        cout << j << endl;
        return false;
    }
};