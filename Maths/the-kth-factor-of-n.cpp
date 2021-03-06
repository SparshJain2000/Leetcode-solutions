//Problem Statement
/*
Given two positive integers n and k.
A factor of an integer n is defined as an integer i where n % i == 0.
Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int kthFactor(int n, int k) {
        int i;
        for (i = 1; i <= sqrt(n); i++)
            if (!(n % i) && --k == 0)
                return i;

        for (i = i - 1; i >= 1; i--)
            if (i * i != n && !(n % i) && !(--k))
                return n / i;

        return -1;
    }
};