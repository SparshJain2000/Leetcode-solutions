//Problem Statement
/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int myAtoi(string str)
    {
        string ans = "";
        bool num = false;
        bool sign = false;
        int q = 0;
        for (q = 0; q < str.length(); q++)
        {
            if (str[q] != ' ')
                break;
        }
        if (str[q] == '-' || str[q] == '+')
        {
            if (str[q] == '-')
                ans = '-';
            q++;
        }

        if ((int)str[q] > (int)'9' || (int)str[q] < (int)'0')
            return 0;
        for (int i = q; i < str.length(); i++)
        {
            if ((int)'9' >= (int)str[i] && (int)'0' <= (int)str[i])
            {
                ans += str[i];
                num = true;
            }
            else
                break;
        }
        int w;
        try
        {
            w = stoi(ans);
        }
        catch (exception e)
        {
            if (ans[0] == '-')
                return pow(-2, 31);
            return pow(2, 31) - 1;
        }
        return w;
    }
};