//Problem Statement
/*
Given an array of positive integers arr, calculate the sum of all possible odd-length subarrays.
A subarray is a contiguous subsequence of the array.
Return the sum of all odd-length subarrays of arr.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int ans = 0;
        int n = mat.size();
        for (int i = 0; i < n; i++)
        {
            ans += mat[i][i];
            if (i != n - 1 - i)
                ans += mat[i][n - 1 - i];
        }
        return ans;
    }
};