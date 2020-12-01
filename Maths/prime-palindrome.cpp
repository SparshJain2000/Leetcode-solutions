//Problem Statement
/*
Find the smallest prime palindrome greater than or equal to N.

Recall that a number is prime if it's only divisors are 1 and itself, and it is greater than 1. 

For example, 2,3,5,7,11 and 13 are primes.

Recall that a number is a palindrome if it reads the same from left to right as it does from right to left. 

For example, 12321 is a palindrome.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    bool isPalindrome(int x)
    {
        string s = to_string(x);
        for (int i = 0; i < s.length(); i++)
            if (s[i] != s[s.length() - 1 - i])
                return false;
        return true;
    }
    bool isPrime(int x)
    {
        if (x == 1)
            return false;
        if (x == 2)
            return true;
        if (!(x % 2))
            return false;
        for (int i = 3; i <= sqrt(x); i += 2)
            if (!(x % i))
                return false;
        return true;
    }

public:
    int primePalindrome(int N)
    {
        int i = N;
        while (true)
        {
            if (isPalindrome(i) && isPrime(i))
                return i;
            i++;
            if (10000000 < i && i < 100000000)
                i = 100000000;
        }
    }
};