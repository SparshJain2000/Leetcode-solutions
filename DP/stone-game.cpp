//Problem Statement
/*
Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    vector<int> piles;
    vector<vector<int>> dp;
    int f(int i, int j)
    {
        if (i == j)
        {
            dp[i][j] = piles[i];
            return dp[i][j];
        }
        if (j - i == 1)
        {
            dp[i][j] = max(piles[i], piles[j]);
            return dp[i][j];
        }
        if (!dp[i + 1][j])
            dp[i + 1][j] = f(i + 1, j);
        if (!dp[i + 1][j])
            dp[i][j - 1] = f(i, j - 1);
        return piles[i] - dp[i + 1][j] >= piles[j] - dp[i][j - 1] ? piles[i] : piles[j];
    }

public:
    //     f(2)=max(a(i),a(j));
    //     f(3)=max(a(i),a(j));
    //     f(4)=max(a(i)-f(3),a(j)-f(3));
    //     f(n)=max(a(i)-f(i+1,j),a(j)-f(i,j-1));

    bool stoneGame(vector<int> &v)
    {
        piles = v;
        dp = vector<vector<int>>(v.size(), vector<int>(v.size(), 0));
        int i = 0, j = piles.size() - 1;
        int alex = 0, lee = 0;
        int chance = 0;
        while (i < j)
        {
            cout << i << " " << j << " : ";
            if (piles[i] - f(i + 1, j) > piles[j] - f(i, j - 1))
                (chance % 2) ? lee += piles[i++] : alex += piles[i++];
            else
                (chance % 2) ? lee += piles[j--] : alex += piles[j--];

            chance++;
            cout << alex << " " << lee << endl;
        }
        (chance % 2) ? lee += piles[i] : alex += piles[i];
        cout << alex << " " << lee << endl;
        return true;
    }
};