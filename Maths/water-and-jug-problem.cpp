//Problem Statement
/*
Given two strings representing two complex numbers.
You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }

   public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % gcd(x, y) == 0);
    }
};