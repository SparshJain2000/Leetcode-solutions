//Problem Statement
/*
You are given an array of n integers, nums, and two arrays of m integers each, l and r, representing the m range queries, where the ith query is the range [l[i], r[i]]. All the arrays are 0-indexed.

Return a list of boolean elements answer, where answer[i] is true if the subarray nums[l[i]], nums[l[i]+1], ... , nums[r[i]] can be rearranged to form an arithmetic sequence, and false otherwise.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        vector<bool> ans;
        for (int i = 0; i < l.size(); i++)
        {
            if (r[i] - l[i] < 2)
                ans.push_back(true);
            else
            {
                vector<int> temp(nums.begin() + l[i], nums.begin() + r[i] + 1);
                sort(temp.begin(), temp.end());
                bool b = true;
                for (int j = 0; j < temp.size() - 1; j++)
                {
                    b &= ((temp[1] - temp[0]) == (temp[j + 1] - temp[j]));
                    if (!b)
                        break;
                }
                ans.push_back(b);
            }
        }
        return ans;
    }
};