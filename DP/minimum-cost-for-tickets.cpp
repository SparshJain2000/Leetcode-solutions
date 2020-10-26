//Problem Statement
/*
In a country popular for train travel, you have planned some train travelling one year in advance.  The days of the year that you will travel is given as an array days.  Each day is an integer from 1 to 365.

Train tickets are sold in 3 different ways:

a 1-day pass is sold for costs[0] dollars;
a 7-day pass is sold for costs[1] dollars;
a 30-day pass is sold for costs[2] dollars.
The passes allow that many days of consecutive travel.  For example, if we get a 7-day pass on day 2, then we can travel for 7 days: day 2, 3, 4, 5, 6, 7, and 8.

Return the minimum number of dollars you need to travel every day in the given list of days.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    unordered_map<int, int> m;
    vector<int> memo;
    int c1, c7, c30;
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        for (int d : days)
            m[d]++;
        memo = vector<int>(366, -1);
        c1 = costs[0], c7 = costs[1], c30 = costs[2];
        return dp(1);
    }
    int dp(int i)
    {
        if (i > 365)
            return 0;
        if (memo[i] != -1)
            return memo[i];
        int ans;
        if (m[i])
            ans = min(min(dp(i + 1) + c1, dp(i + 7) + c7), dp(i + 30) + c30);
        else
            ans = dp(i + 1);
        memo[i] = ans;
        return ans;
    }
};