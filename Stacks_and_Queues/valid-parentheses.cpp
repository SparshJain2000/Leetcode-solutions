//Problem Statement
/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> v(s.begin(), s.end());
        stack<char> st;
        for (int i = 0; i < v.size(); i++)
        {
            if (s.at(i) == '(' || s.at(i) == '[' || s.at(i) == '{')
                st.push(s.at(i));
            if (s.at(i) == ')')
            {
                if (st.size() == 0)
                    return false;
                if (st.top() == '(')
                    st.pop();
                else
                    return false;
            }
            if (s.at(i) == ']')
            {
                if (st.size() == 0)
                    return false;
                if (st.top() == '[')
                    st.pop();
                else
                    return false;
            }
            if (s.at(i) == '}')
            {
                if (st.size() == 0)
                    return false;
                if (st.top() == '{')
                    st.pop();
                else
                    return false;
            }
        }
        if (st.size() != 0)
            return false;
        return true;
    }
};