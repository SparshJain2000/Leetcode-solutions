//Problem Statement
/*
Given an array of integers arr.

We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).

Let's define a and b as follows:

a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.

Return the number of triplets (i, j and k) Where a == b.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countTriplets(vector<int> &v)
    {
        for (int i = 1; i < v.size(); i++)
            v[i] ^= v[i - 1];
        int ans = 0;
        for (int i = 1; i < v.size(); i++)
            for (int j = 0; j <= i; j++)
            {
                int q = (j >= 1) ? v[j - 1] ^ v[i] : v[i];
                if (i - j >= 1 && q == 0)
                    ans += i - j;
            }
        return ans;
    }
};