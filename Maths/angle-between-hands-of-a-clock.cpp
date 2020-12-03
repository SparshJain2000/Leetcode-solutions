//Problem Statement
/*
Given two strings representing two complex numbers.
You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    double angleClock(int hour, int minutes)
    {
        double angle = abs((hour % 12 + (double)minutes / 60) * 30 - (minutes % 60) * 6);
        return min(angle, 360 - angle);
    }
};