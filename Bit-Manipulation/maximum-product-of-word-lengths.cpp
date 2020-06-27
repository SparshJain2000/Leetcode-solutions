//Problem Statement
/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. 
You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        vector<int> arr;
        if (!words.size())
            return 0;
        for (string s : words)
        {
            int x = 0;
            for (char c : s)
            {
                x = x | (1 << ((int)c - (int)'a'));
            }
            arr.push_back(x);
        }
        int max = 0;
        for (int i = 0; i < words.size() - 1; i++)
        {
            for (int j = i + 1; j < words.size(); j++)
            {
                if ((arr[i] & arr[j]) == 0)
                    max = (words[i].length() * words[j].length() > max) ? words[i].length() * words[j].length() : max;
            }
        }
        return max;
    }
};