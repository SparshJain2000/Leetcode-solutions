//Problem Statement
/*
Given an integer array arr, you should partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.

Return the largest sum of the given array after partitioning.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        vector<int> dp(arr.size(), 0);

        for (int i = 0; i < arr.size(); i++)
        {
            int m = 0;
            for (int j = 1; j <= k && (j - 1) <= i; j++)
            {
                m = max(m, arr[i - (j - 1)]);
                dp[i] = max(dp[i], (i - j >= 0 ? dp[i - j] : 0) + (j * m));
            }
        }
        // for (int i : dp)
        //     cout << i << " ";
        return dp[arr.size() - 1];
    }
};
int main()
{
    Solution s;
    vector<int> arr({1, 15, 7, 9, 2, 5, 10});

    int ans = s.maxSumAfterPartitioning(arr, 3);
    cout << ans << endl;
}