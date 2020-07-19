
//Problem Statement
/*Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.*/
#include <bits/stdc++.h>
class Solution
{
public:
    int bits(int n)
    {
        int c = 0;
        while (n)
        {
            n &= (n - 1);
            n >>= 1;
            c++;
        }
        return c;
    }
    vector<int> countBits(int num)
    {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1; i <= num; i++)
        {
            int w = (i % 1) ? ans.at(i - 1) + 1 : bits(i);
            ans.push_back(w);
        }
        return ans;
    }
};