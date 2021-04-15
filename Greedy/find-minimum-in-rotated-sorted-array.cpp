//Problem Statement
/*
    Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:
    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.
    Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
    Given the sorted rotated array nums, return the minimum element of this array.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int findMin(vector<int>& nums) {
        /* 
            //Nāive approach O(N)
            for (int i = 0; i < nums.size() - 1; i++)
                if (nums[i] > nums[i + 1]) return nums[i + 1];
            return nums[0];
         */

        //Using binary search
        int l = 0, h = nums.size() - 1;
        while (l < h) {
            int mid = (l + h) / 2;
            (nums[mid] < nums[h]) ? h = mid : l = mid + 1;
        }
        return nums[l];
    }
};