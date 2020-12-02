//Problem Statement
/*
Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k, that is, sums up to n*k where n is also an integer.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            for (int i = 2; i <= nums.size(); i++)
            {
                int sum = 0;
                for (int j = 0; j < i; j++)
                    sum += nums.at(j);

                for (int j = i; j < nums.size(); j++)
                {
                    if (sum == 0)
                        return true;
                    sum = sum - nums.at(j - i) + nums.at(j);
                }
                if (sum == 0)
                    return true;
            }
        }
        else
        {
            for (int i = 2; i <= nums.size(); i++)
            {
                int sum = 0;
                for (int j = 0; j < i; j++)
                    sum += nums.at(j);

                for (int j = i; j < nums.size(); j++)
                {
                    if (sum % k == 0)
                        return true;
                    sum = sum - nums.at(j - i) + nums.at(j);
                }
                if (sum % k == 0)
                    return true;
            }
        }
        return false;
    }
};