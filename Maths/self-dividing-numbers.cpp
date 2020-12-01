//Problem Statement
/*
A self-dividing number is a number that is divisible by every digit it contains.
For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
Also, a self-dividing number is not allowed to contain the digit zero.
Given a lower and upper number bound, output a list of every possible self dividing number, including the bounds if possible.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> ans;
        for (int i = left; i <= right; i++)
        {
            int temp = i;
            bool isself = i != 0;
            while (isself && temp)
            {
                isself = temp % 10 ? i % (temp % 10) == 0 : false;
                if (!isself)
                    break;
                temp /= 10;
            }
            if (isself)
                ans.push_back(i);
        }
        return ans;
    }
};