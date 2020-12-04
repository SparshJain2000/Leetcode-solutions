//Problem Statement
/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return 0;
        int i = 0, j = 0;
        for (int k = 0; k < n; k++)
        {
            int far = 0;
            for (int w = i; w <= j; w++)
            {
                if (w + nums[w] >= n - 1)
                    return k + 1;
                far = max(far, nums[w] + w);
            }
            i = j + 1;
            j = far;
        }
        return -1;
    }
};