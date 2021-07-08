//Problem Statement
/*
We can scramble a string s to get a string t using the following algorithm:

If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool util(string s1, string s2) {
        int n = s1.length();
        int n2 = s2.length();
        if (n != n2) return false;
        if (s1 == s2) return true;
        string key = s1 + " " + s2;
        if (dp.find(key) != dp.end()) return dp[key];

        for (int i = 1; i < n; i++) {
            if ((util(s1.substr(0, i), s2.substr(0, i)) && util(s1.substr(i, n - i), s2.substr(i, n - i))) ||
                (util(s1.substr(0, i), s2.substr(n - i, i)) && util(s1.substr(i, n - i), s2.substr(0, n - i))))
                return dp[key] = true;
        }
        return dp[key] = false;
    }
    unordered_map<string, bool> dp;
    bool isScramble(string s1, string s2) {
        return util(s1, s2);
    }
};