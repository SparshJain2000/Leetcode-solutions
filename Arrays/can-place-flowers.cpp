//Problem Statement
/*
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
You can assume that you can always reach the last index.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        if (flowerbed.size() < n)
            return false;
        if (flowerbed.size() == n && n == 1)
            return flowerbed[0] == 0;
        for (int i = 0; i < flowerbed.size() - 1; i++) {
            int cons = 1;
            int pre = i;
            while (i < flowerbed.size() - 1 && flowerbed[i] == flowerbed[i + 1] && flowerbed[i] == 0)
                cons++, i++;

            if (i == flowerbed.size() - 1 && flowerbed[i - 1] == flowerbed[i] && flowerbed[i] == 0)
                cons++;
            if (--cons)
                n -= (pre ? cons / 2 : (++cons) / 2);
            if (n <= 0)
                return true;
            if (i != pre)
                i--;
        }
        return n <= 0;
    }
};