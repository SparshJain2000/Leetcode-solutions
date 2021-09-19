/*
Problem Statement
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string longestCommonPrefix(vector<string>& arr) {
        int N = arr.size();
        string pre = "";
        for (int j = 0; j < arr[0].length(); j++) {
            char temp = arr[0][j];
            for (int i = 1; i < N; i++) {
                if (j >= arr[i].length() || arr[i][j] != temp)
                    return pre;
            }
            pre += temp;
        }
        return pre;
    }
};