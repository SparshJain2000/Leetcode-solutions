//Problem Statement
/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int trap(vector<int> &height)
    {
        if (height.size() == 0 || height.size() == 1)
            return 0;
        int ans = 0;
        for (int i = 0; i < (int)height.size() - 1;)
        {
            int j = i + 1;
            int max = 0;
            int temp = 0;
            int j1 = i + 1;
            while (height.at(i) > height.at(j) && j < height.size())
            {
                if (height.at(j) > max)
                {
                    max = height.at(j);
                    j1 = j;
                }

                if (j == (int)height.size() - 1)
                    break;
                j++;
                if (height.at(j) >= height.at(i))
                {
                    max = height[j];
                    j1 = j;
                }
            }
            int z = height.at(j1);
            if (height.at(i) <= height.at(j1))
            {
                z = height[i];
            }
            if (max > height.at(i + 1))
            {
                for (int k = i + 1; k < j1; k++)
                {
                    temp += (z - height.at(k));
                }
            }
            else
                j = i + 1;
            ans += temp;
            i = j1;
        }
        return ans;
    }
};