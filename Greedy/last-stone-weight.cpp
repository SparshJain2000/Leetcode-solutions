//Problem Statement
/*
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        while (stones.size() > 1)
        {
            sort(stones.begin(), stones.end());
            int y = stones.back() - stones.at(stones.size() - 2);
            vector<int> temp(stones.begin(), stones.end() - 2);
            stones = temp;
            if (y != 0)
                stones.push_back(y);
        }
        if (stones.size() == 0)
            return 0;
        return stones.at(0);
    }
};