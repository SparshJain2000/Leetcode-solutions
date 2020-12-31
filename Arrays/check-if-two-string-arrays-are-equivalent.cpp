//Problem Statement
/*
Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
A string is represented by an array if the array elements concatenated in order forms the string.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
        //Generate 2 strings and compare
        /*
        string ans="",ans1="";
        for(string s:word1) ans+=s;
        for(string s:word2) ans1+=s;
        return ans==ans1;
        */

        //check char by char (less storage consumption)
        int i1 = 0, i2 = 0, a1 = 0, a2 = 0;
        while (a1 < word1.size() && a2 < word2.size()) {
            if (word1[a1][i1++] != word2[a2][i2++])
                return false;
            if (i1 == word1[a1].length())
                a1++, i1 = 0;
            if (i2 == word2[a2].length())
                a2++, i2 = 0;
        }
        return true;
    }
};