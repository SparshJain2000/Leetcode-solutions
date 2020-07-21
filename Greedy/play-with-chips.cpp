//Problem Statement
/*
There are some chips, and the i-th chip is at position chips[i].

You can perform any of the two following types of moves any number of times (possibly zero) on any chip:

Move the i-th chip by 2 units to the left or to the right with a cost of 0.
Move the i-th chip by 1 unit to the left or to the right with a cost of 1.
There can be two or more chips at the same position initially.

Return the minimum cost needed to move all the chips to the same position (any position).
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int minCostToMoveChips(vector<int> &chips)
    {
        map<int, int> m;
        for (int i : chips)
            m[i]++;
        int even = 0, odd = 0, i = 0;
        for (pair<int, int> p : m)
        {
            i++;
            if (p.first & 1)
                odd += p.second;
            else
                even += p.second;
        }
        return min(even, odd);
    }
};