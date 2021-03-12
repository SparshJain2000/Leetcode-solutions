//Problem Statement
/*
Given the array of integers nums, you will choose two different indices i and j of that array. Return the maximum value of (nums[i]-1)*(nums[j]-1).
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int m = 0, s = 0;
        for (int i : nums) {
            if (i >= m)
                s = m, m = i;
            else if (i > s)
                s = i;
        }
        return (m - 1) * (s - 1);
    }
};