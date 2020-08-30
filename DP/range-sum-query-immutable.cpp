//Problem Statement
/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
*/
#include <bits/stdc++.h>
using namespace std;
class NumArray
{
    vector<int> arr;

public:
    NumArray(vector<int> &nums)
    {
        if (nums.size())
        {
            arr.push_back(nums[0]);
            for (int i = 1; i < nums.size(); i++)
            {
                arr.push_back(arr[i - 1] + nums[i]);
            }
        }
    }

    int sumRange(int i, int j)
    {
        int sub = (i - 1) < 0 ? 0 : arr[i - 1];
        return arr[j] - sub;
    }
};