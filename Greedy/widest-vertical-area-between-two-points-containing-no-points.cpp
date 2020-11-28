/*
Problem Statement
Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.

A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.

Note that points on the edge of a vertical area are not considered included in the area.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class Solution
{
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points)
    {
        vector<int> v;
        for (vi a : points)
            v.push_back(a[0]);
        sort(v.begin(), v.end());
        int ans = INT_MIN;
        for (int i = 0; i < points.size() - 1; i++)
            ans = max(ans, v[i + 1] - v[i]);
        return ans;
    }
};