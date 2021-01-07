//Problem Statement
/*
Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.

For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].

Note: The length of temperatures will be in the range [1, 30000]. Each temperature will be an integer in the range [30, 100].
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int> &T) {
        vector<int> ans(T.size(), 0);
        vector<int> temp(101, INT_MAX);

        for (int i = T.size() - 1; i >= 0; i--) {
            int z = INT_MAX;
            for (int j = T[i] + 1; j <= 100; j++) {
                z = min(z, temp[j]);
                if (z - i == 1)
                    break;
            }
            ans[i] = z == INT_MAX ? 0 : z - i;
            temp[T[i]] = i;
        }
        return ans;
    }
};