//Problem Statement
/*
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
class Solution {
   public:
    int countVowelStrings(int n) {
        vi arr(6, 1);
        for (int i = 1; i < n; i++)
            for (int j = 2; j <= 5; j++)
                arr[j] += arr[j - 1];

        return accumulate(arr.begin(), arr.end(), 0) - 1;
    }
};
