//Problem Statement
/*
    You are given an array rectangles where rectangles[i] = [li, wi] represents the ith rectangle of length li and width wi.
    You can cut the ith rectangle to form a square with a side length of k if both k <= li and k <= wi. For example, if you have a rectangle [4,6], you can cut it to get a square with a side length of at most 4.
    Let maxLen be the side length of the largest square you can obtain from any of the given rectangles.
    Return the number of rectangles that can make a square with a side length of maxLen. 
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int countGoodRectangles(vector<vector<int>> &rectangles) {
        unordered_map<int, int> m;
        for (auto v : rectangles) m[min(v[0], v[1])]++;
        return max_element(m.begin(), m.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
                   return a.first < b.first;
               })->second;
    }
};