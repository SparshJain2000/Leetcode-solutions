//Problem Statement
/*
Given the number k, return the minimum number of Fibonacci numbers whose sum is equal to k, whether a Fibonacci number could be used multiple times.
The Fibonacci numbers are defined as:

F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2 , for n > 2.
It is guaranteed that for the given constraints we can always find such fibonacci numbers that sum k
*/
#include <bits/stdc++.h>
class Solution
{
private:
    void swap(int &a, int &b)
    {
        b = a ^ b;
        a = a ^ b;
        b = a ^ b;
    }

public:
    int findMinFibonacciNumbers(int k)
    {
        int a = 0, b = 1;
        while (b <= k)
        {
            swap(a, b);
            b += a;
        }
        int ans = 0;
        while (k > 0)
        {
            while (a > k)
            {
                swap(a, b);
                a -= b;
            }
            k -= a;
            ans++;
        }
        return ans;
    }
};