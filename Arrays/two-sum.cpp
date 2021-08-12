//Problem Statement
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(target - nums[i]) != mp.end()) {
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return ans;
    }
};