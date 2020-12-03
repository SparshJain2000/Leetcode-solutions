
//Problem Statement
/*
Given an m x n 2d grid map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
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