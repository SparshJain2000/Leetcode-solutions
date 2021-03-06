//Problem Statement
/*
    Given an array A of non-negative integers, return an array consisting of all the even elements of A, followed by all the odd elements of A.
    You may return any answer array that satisfies this condition.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        int j = A.size() - 1;
        while (i < j) {
            if (A[i] & 1 && !(A[j] & 1))
                swap(A[i], A[j]);
            if (!(A[i] & 1)) i++;
            if (A[j] & 1) j--;
        }
        return A;
    }
};