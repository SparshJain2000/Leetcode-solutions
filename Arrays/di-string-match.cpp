//Problem Statement
/*
Given a string S that only contains "I" (increase) or "D" (decrease), let N = S.length.
Return any permutation A of [0, 1, ..., N] such that for all i = 0, ..., N-1:

If S[i] == "I", then A[i] < A[i+1]
If S[i] == "D", then A[i] > A[i+1]
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> diStringMatch(string S)
    {
        int n = S.length();
        vector<int> ans(n + 1, 0);
        int l = 0, h = n;
        for (int i = 0; i < n; i++)
        {
            ans[i] = (S[i] == 'I') ? l++ : h--;
        }
        ans[n] = l;
        return ans;
    }
};