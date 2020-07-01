//Problem Statement
/*
Given a string s of '(' , ')' and lowercase English characters. 

Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

Formally, a parentheses string is valid if and only if:

It is the empty string, contains only lowercase characters, or
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
 */

#include <bits/stdc++.h>
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        vector<char> v(s.begin(), s.end());
        stack<char> st;
        stack<int> ind;
        for (int i = 0; i < v.size(); i++)
        {
            if (s.at(i) == '(')
            {
                st.push(s.at(i));
                ind.push(i);
            }
            if (s.at(i) == ')')
            {
                if (st.size() == 0)
                    s.replace(i, 1, "-");
                else
                {
                    if (st.top() == '(')
                    {
                        st.pop();
                        ind.pop();
                    }
                    else
                        s.replace(i, 1, "-");
                }
            }
        }
        while (!ind.empty())
        {
            s.erase(s.begin() + ind.top());
            ind.pop();
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '-')
            {
                s.erase(s.begin() + i);
                i--;
            }
        }
        return s;
    }
};