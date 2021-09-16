/*
Problem Statement
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> plusOne(vector<int>& arr) {
        reverse(arr.begin(), arr.end());
        int carry = 1;
        for (int i = 0; i < arr.size(); i++) {
            arr[i] += carry;
            carry = arr[i] / 10;
            arr[i] %= 10;
        }
        if (carry) arr.push_back(carry);
        reverse(arr.begin(), arr.end());
        return arr;
    }
};