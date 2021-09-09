/*
Problem Statement

A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.
Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int n_min = n, m_min = m;
        for (auto v : ops) {
            n_min = min(n_min, v[1]);
            m_min = min(m_min, v[0]);
        }
        return n_min * m_min;
    }
};