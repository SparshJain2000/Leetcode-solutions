//Problem Statement
/*
    You are given n pairs of numbers. In every pair, the first number is always smaller than the second number.

    Now, we define a pair (c, d) can follow another pair (a, b) if and only if b < c. Chain of pairs can be formed in this fashion.

    Given a set of pairs, find the length longest chain which can be formed. You needn't use up all the given pairs. You can select pairs in any order.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int findLongestChain(vector<vector<int>> &p) {
        sort(p.begin(), p.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });
        int n = p.size();
        vector<int> dp(n + 1, 1);
        dp[0] = 0;
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++)
                if (p[i - 1][0] > p[j - 1][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            ;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};