//Problem Statement
/*
Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int j = 0;
        for (int i = 0; i < chars.size(); i++)
        {

            while (i < chars.size() - 1 && chars[i] == chars[i + 1])
            {
                count++;
            }
            chars[j++] = chars[i];
            string temp = to_string(count);
            for (char c : temp)
                chars[j++] = c;
        }
        return j;
    }
};