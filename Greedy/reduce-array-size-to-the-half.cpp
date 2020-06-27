//Problem Statement
/*
Given an array arr.  You can choose a set of integers and remove all the occurrences of these integers in the array.

Return the minimum size of the set so that at least half of the integers of the array are removed.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int s = arr.size();
        vector<int> x;
        x.push_back(1);
        for (int i = 1; i < s; i++)
        {
            if (arr.at(i - 1) == arr.at(i))
                x.back()++;
            else
            {
                x.push_back(1);
            }
        }
        sort(x.begin(), x.end());
        int sum = 0;
        for (int i = x.size() - 1; i >= 0; i--)
        {
            sum += x.at(i);
            if (sum >= s / 2)
                return (x.size() - i);
        }
        return 0;
    }
};