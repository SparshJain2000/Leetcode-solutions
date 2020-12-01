//Problem Statement
/*
On a plane there are n points with integer coordinates points[i] = [xi, yi]. Your task is to find the minimum time in seconds to visit all points.
You can move according to the next rules:
In one second always you can either move vertically, horizontally by one unit or diagonally (it means to move one unit vertically and one unit horizontally in one second).
You have to visit the points in the same order as they appear in the array.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        vector<int> curr;
        curr = points[0];
        int sum = 0;
        for (auto i = points.begin() + 1; i != points.end(); ++i)
        {
            int xdiff = abs((*i)[0] - curr[0]);
            int ydiff = abs((*i)[1] - curr[1]);
            if (ydiff > xdiff)
            {
                sum += xdiff;
                if ((*i)[1] < curr[1])
                    sum += abs((*i)[1] - (curr[1] - xdiff));
                else
                    sum += abs((*i)[1] - (curr[1] + xdiff));
            }
            else
            {
                sum += ydiff;
                if ((*i)[0] < curr[0])
                    sum += abs((*i)[0] - (curr[0] - ydiff));
                else
                    sum += abs((*i)[0] - (curr[0] + ydiff));
            }
            curr = (*i);
        }
        return sum;
    }
};