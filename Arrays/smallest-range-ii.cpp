//Problem Statement
/*
Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, and add x to A[i] (only once).

After this process, we have some array B.

Return the smallest possible difference between the maximum value of B and the minimum value of B.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int smallestRangeII(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int ans = A.back() - A[0];

        for (int i = 0; i < A.size() - 1; i++) {
            int high = max(A.back() - k, A[i] + k);
            int low = min(A[0] + k, A[i + 1] - k);
            ans = min(ans, high - low);
        }
        return ans;
    }
};