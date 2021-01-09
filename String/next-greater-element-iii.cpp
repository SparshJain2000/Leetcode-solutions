//Problem Statement
/*
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.
Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        int len = str.length();
        int min_ele = INT_MAX;
        int ind = -1;
        int i = len - 1;
        for (; i >= 1; i--) {
            if (str[i] > str[i - 1]) {
                int x = str[i - 1], smallest = i;
                for (int j = i + 1; j < len; j++)
                    if (str[j] > x && str[j] <= str[smallest])
                        smallest = j;
                char temp = str[i - 1];
                str[i - 1] = str[smallest];
                str[smallest] = temp;
                break;
            }
        }
        if (i == 0) return -1;
        sort(str.begin() + i, str.end());
        long ans = stol(str);
        return ans <= INT_MAX ? ans : -1;
    }
};
//5 4 3 9 8 7