//Problem Statement
/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool checkStraightLine(vector<vector<int>> &coordinates) {
        int n = coordinates.size();
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[n - 1][0];
        int y2 = coordinates[n - 1][1];
        for (int i = 1; i < n - 1; i++)
            if ((x2 - x1) * (coordinates[i][1] - y1) != (y2 - y1) * (coordinates[i][0] - x1))
                return false;
        return true;
    }
};