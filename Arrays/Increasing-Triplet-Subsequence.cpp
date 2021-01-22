//Problem Statement
/*
Given an integer array nums, return true if there exists a triple of indices(i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k].If no such indices exists, return false.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (int x : nums) {
            if (x <= c1)
                c1 = x;
            else if (x <= c2)
                c2 = x;
            else
                return true;
        }
        return false;
    }
};