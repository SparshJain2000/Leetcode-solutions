//Problem Statement
/*
Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.

A subarray is a contiguous subsequence of the array.

Return the sum of all odd-length subarrays of arr.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int sumOddLengthSubarrays(vector<int> &arr) {
        int sum = 0;
        for (int i = 1; i <= arr.size(); i += 2) {
            int sum2 = 0;
            for (int j = 0; j < i; j++)
                sum2 += arr[j];
            sum += sum2;
            for (int j = i; j < arr.size(); j++) {
                sum2 += arr[j] - arr[j - i];
                sum += sum2;
            }
            cout << sum << " ";
        }
        return sum;
    }
};