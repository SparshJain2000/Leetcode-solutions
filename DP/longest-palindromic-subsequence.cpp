//Problem Statement
/*
Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        string p = s;
        reverse(p.begin(), p.end());
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        // ans= LCS(s,reverse(s))
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == p[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int i = n, j = n;
        string ans = "";
        while (i > 0 && j > 0 && dp[i][j] != 0) {
            if (s[i - 1] == p[j - 1]) {
                ans = s[i - 1] + ans;
                i--;
                j--;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
        cout << ans << endl;

        return dp[n][n];
    }
};