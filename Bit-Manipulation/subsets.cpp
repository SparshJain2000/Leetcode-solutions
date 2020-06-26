//Problem Statement
/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < (1 << nums.size()); i++)
        {
            ans.push_back(vector<int>());
            for (int j = 0; j < nums.size(); j++)
            {
                if ((1 << j) & i)
                    ans.at(i).push_back(nums.at(j));
            }
        }
        return ans;
    }
};