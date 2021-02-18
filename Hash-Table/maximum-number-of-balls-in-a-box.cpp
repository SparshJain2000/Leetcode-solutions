
//Problem Statement
/*
    You are working in a ball factory where you have n balls numbered from lowLimit up to highLimit inclusive (i.e., n == highLimit - lowLimit + 1), and an infinite number of boxes numbered from 1 to infinity.
    Your job at this factory is to put each ball in the box with a number equal to the sum of digits of the ball's number. For example, the ball number 321 will be put in the box number 3 + 2 + 1 = 6 and the ball number 10 will be put in the box number 1 + 0 = 1.
    Given two integers lowLimit and highLimit, return the number of balls in the box with the most balls.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int count(int x) {
        string s = to_string(x);
        return accumulate(s.begin(), s.end(), 0, [](const int &a, const char &b) {
            return a + b - '0';
        });
    }

   public:
    int countBalls(int lowLimit, int highLimit) {
        if (lowLimit == highLimit) return 1;

        /* Bruteforce
            for(int i=lowLimit;i<=highLimit;i++) {
                int cnt=count((i));
                m[cnt]++;
                ans=max(ans,m[cnt]);
            }
        */
        //Bruteforce with optimization;
        unordered_map<int, int> m;
        int ans = 0;
        int cnt = count(lowLimit);
        while (lowLimit % 10 && lowLimit++ < highLimit) m[cnt++]++;
        while (lowLimit <= highLimit) {
            cnt = count(lowLimit);
            for (int i = 0; i < 10 && lowLimit++ <= highLimit; i++) m[cnt++]++;
        }
        return max_element(m.begin(), m.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
                   return a.second < b.second;
               })
            ->second;
    }
};