//Problem Statement
/*
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> st;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ']')
            {
                string str = "";
                while (!st.empty() && st.top()[0] != '[')
                    str = st.top() + str, st.pop();
                string num = "";
                if (!st.empty())
                    st.pop();
                while (!st.empty() && isdigit(st.top()[0]))
                    num = st.top() + num, st.pop();
                int x = num == "" ? 1 : stoi(num);
                num = "";
                for (int j = 1; j <= x; j++)
                    num += str;
                st.push(num);
            }
            else
                st.push(string(1, s[i]));
        }
        string ans = "";
        while (!st.empty())
            ans = st.top() + ans, st.pop();
        return ans;
    }
};