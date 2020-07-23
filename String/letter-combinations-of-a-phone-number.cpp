//Problem Statement
/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> s;
        if (digits.length() == 0)
            return s;
        map<char, string> m;
        m.insert(pair<char, string>('2', "abc"));
        m.insert(pair<char, string>('3', "def"));
        m.insert(pair<char, string>('4', "ghi"));
        m.insert(pair<char, string>('5', "jkl"));
        m.insert(pair<char, string>('6', "mno"));
        m.insert(pair<char, string>('7', "pqrs"));
        m.insert(pair<char, string>('8', "tuv"));
        m.insert(pair<char, string>('9', "wxyz"));
        s.push_back("");
        // cout<<s.size()<<" "<<m[2]<<endl;
        for (int i = 0; i < digits.length(); i++)
        {
            string w = m[digits[i]];
            vector<string> temp;
            for (int j = 0; j < s.size(); j++)
                for (int k = 0; k < w.length(); k++)
                    temp.push_back(s.at(j) + w[k]);
            s = temp;
        }
        return s;
    }
};