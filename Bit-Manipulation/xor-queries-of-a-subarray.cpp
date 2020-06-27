//Problem Statement
/*
Given the array arr of positive integers and the array queries where queries[i] = [Li, Ri], 
for each query i compute the XOR of elements from Li to Ri (that is, arr[Li] xor arr[Li+1] xor ... xor arr[Ri] ). 
Return an array containing the result for the given queries.
*/
#include <bits/stdc++.h>

class Solution
{
public:
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        vector<int> temp;
        vector<int> ans;
        int w = 0;
        for (int i : arr)
        {
            w ^= i;
            temp.push_back(w);
        }
        for (vector<int> x : queries)
        {
            int l = x.at(0), r = x.at(1);
            ans.push_back(l == 0 ? temp.at(r) : temp.at(r) ^ temp.at(l - 1));
        }
        return ans;
    }
};