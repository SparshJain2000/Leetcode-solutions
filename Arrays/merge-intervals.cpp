//Problem Statement
/*
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        int last = INT_MIN;
        for (auto vi : intervals) {
            if (vi[0] > last)
                ans.push_back(vi);
            else
                ans.back()[1] = max(vi[1], last);
            last = max(last, vi[1]);
        }
        return ans;
    }
};