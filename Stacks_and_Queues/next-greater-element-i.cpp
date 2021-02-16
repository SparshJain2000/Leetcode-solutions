//Problem Statement
/*
    You are given two integer arrays nums1 and nums2 both of unique elements, where nums1 is a subset of nums2.
    Find all the next greater numbers for nums1's elements in the corresponding places of nums2.
    The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, return -1 for this number.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int i : nums2) {
            while (!s.empty() && s.top() < i) m[s.top()] = i, s.pop();
            s.push(i);
        }
        for (int& n : nums1) n = m[n] ? m[n] : -1;
        return nums1;
    }
};