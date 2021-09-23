/*
Problem Statement
Given a string s, return the longest palindromic substring in s.

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string longestPalindrome(string s) {
        int i = 0;
        int n = s.length();
        string res = "";
        int ans = 0;
        char c = s[0];
        int temp = 1;
        for (int i = 1; i < n; i++)
            if (s[i] == c) temp++;
        if (temp == n) return s;
        while (i < n) {
            int j = i + 1;
            int k = i - 1;
            int temp = 1;
            string ts;
            ts += s[i];
            while (k > -1 && j < n && s[j] == s[k]) {
                ts = (s[k] + ts + s[j]);
                temp += 2;
                k--;
                j++;
            }
            if (temp > ans) ans = temp, res = ts;
            i++;
        }

        int j = 1;
        i = 0;
        while (i < n - 1 && j < n) {
            int k = j;
            int l = i;
            int temp = 0;
            string ts = "";
            while (k < n && l > -1 && s[k] == s[l]) {
                ts = (s[l] + ts + s[k]);
                k++, l--;
                temp += 2;
            }
            if (temp > ans) ans = temp, res = ts;
            i++;
            j++;
        }

        return res;
    }
};