//Problem Statement
/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, 0));
        int n = s.length();
        int m = p.length();
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++)
            if (p[i - 1] == '*') dp[0][i] = dp[0][i - 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                // cout<<dp[i][j]<<" ";
            }
        }
        return dp[n][m];
    }
};