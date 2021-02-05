
//Problem Statement
/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.
Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int i = 2; i < n; i++)
            if (nums[i] == nums[i - 2 - count])
                count++;
            else
                nums[i - count] = nums[i];
        return n - count;
    }
};