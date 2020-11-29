//Problem Statement
/*
For a string sequence, a string word is k-repeating if word concatenated k times is a substring of sequence. The word's maximum k-repeating value is the highest value k where word is k-repeating in sequence. If word is not a substring of sequence, word's maximum k-repeating value is 0.

Given strings sequence and word, return the maximum k-repeating value of word in sequence.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxRepeating(string sequence, string word)
    {
        if (sequence == word)
            return 1;
        if (sequence.length() < word.length())
            return 0;
        int inc = word.length();
        int ans = INT_MIN;
        for (int i = 0; i < sequence.length(); i++)
        {
            int temp = 0;
            while (word == sequence.substr(i, inc))
                temp++, i += inc;
            ans = max(temp, ans);
        }
        return ans == INT_MIN ? 0 : ans;
    }
};