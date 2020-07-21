//Problem Statement
/*
Given numBottles full water bottles, you can exchange numExchange empty water bottles for one full water bottle.

The operation of drinking a full water bottle turns it into an empty bottle.

Return the maximum number of water bottles you can drink.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int numWaterBottles(int b, int e)
    {
        int ans = 0;
        int empty = 0;
        while (b)
        {
            ans += b;
            empty += b;
            b = empty / e;
            empty = empty % e;
        }
        return ans;
    }
};