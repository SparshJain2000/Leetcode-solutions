/*
Problem Statement

Given a number N, return a string consisting of "0"s and "1"s that represents its value in base -2 (negative two).
The returned string must have no leading zeroes, unless the string is "0".
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string baseNeg2(int N) {
        string ans = "";
        while (N!=0) {
            ans += to_string(N & 1);
            N = -(N >> 1);
        }
        reverse(ans.begin(), ans.end());
        return ans == "" ? "0" : ans;
    }
};
