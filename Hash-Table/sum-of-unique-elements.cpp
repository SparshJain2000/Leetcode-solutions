//Problem Statement
/*
    You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.
    Return the sum of all the unique elements of nums.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i : nums) m[i]++;
        int ans = 0;
        for (int i : nums) ans += m[i] == 1 ? i : 0;
        return ans;
    }
};