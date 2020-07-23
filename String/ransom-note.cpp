//Problem Statement
/*
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        short m[26] = {0};
        for (char c : magazine)
            m[c - 97]++;
        for (char c : ransomNote)
            if (!(m[c - 97]--))
                return false;
        return true;
    }
};