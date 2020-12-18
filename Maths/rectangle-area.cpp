//Problem Statement
/*
Find the total area covered by two rectilinear rectangles in a 2D plane.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int max(int a, int b) {
        if (a > b)
            return a;
        return b;
    }
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int left = max(A, E);
        int top = min(D, H);
        int right = min(C, G);
        int bottom = max(B, F);
        int overlap = 0;
        if (left < right && top > bottom)
            overlap = (right - left) * (top - bottom);
        return (int)((long)(C - A) * (long)(D - B) + (long)(G - E) * (long)(H - F) - overlap);
    }
};