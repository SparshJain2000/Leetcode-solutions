//Problem Statement
/*
Given the array prices where prices[i] is the price of the ith item in a shop. There is a special discount for items in the shop, if you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i], otherwise, you will not receive any discount at all.

Return an array where the ith element is the final price you will pay for the ith item of the shop considering the special discount.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        int n = prices.size();
        s.push(prices[n - 1]);
        for (int i = n - 2; i >= 0; i--) {
            while (!s.empty() && prices[i] < s.top()) s.pop();
            if (s.empty())
                s.push(prices[i]);
            else {
                int temp = prices[i];
                prices[i] -= s.top();
                s.push(temp);
            }
        }
        return prices;
    }
};