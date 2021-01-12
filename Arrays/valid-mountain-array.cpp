//Problem Statement
/*
Given an array of integers arr, return true if and only if it is a valid mountain array.
Recall that arr is a mountain array if and only if:
arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
    arr[0] < arr[1] < ... < arr[i - 1] < A[i]
    arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool validMountainArray(vector<int> &arr) {
        if (arr.size() < 3)
            return false;
        int i = 0;
        while (i < arr.size() - 1 && arr[i] < arr[i + 1])
            i++;
        if (i == 0 || i == arr.size() - 1)
            return false;
        i++;
        while (i < arr.size())
            if (arr[i - 1] <= arr[i++])
                return false;
        return true;
    }
};