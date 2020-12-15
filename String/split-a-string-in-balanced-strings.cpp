/*
Problem Statement
Balanced strings are those who have equal quantity of 'L' and 'R' characters.

Given a balanced string s split it in the maximum amount of balanced strings.

Return the maximum amount of splitted balanced strings.*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int balancedStringSplit(string s) {
        int count = 0;
        int ans = 0;
        for (char c : s) {
            count += (c == 'L') ? 1 : -1;
            if (!count)
                ans++;
        }
        return ans;
    }
};