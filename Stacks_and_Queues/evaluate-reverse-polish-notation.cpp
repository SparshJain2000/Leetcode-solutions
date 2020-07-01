//Problem Statement
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.
*/

#include <bits/stdc++.h>
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int st[tokens.size()];
        int top = -1;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens.at(i) == "+")
            {
                int x = st[top--];
                int y = st[top--];
                st[++top] = (y + x);
            }
            else if (tokens.at(i) == "-")
            {
                int x = st[top--];
                int y = st[top--];
                st[++top] = (y - x);
            }
            else if (tokens.at(i) == "*")
            {
                int x = st[top--];
                int y = st[top--];
                st[++top] = (y * x);
            }
            else if (tokens.at(i) == "/")
            {
                int x = st[top--];
                int y = st[top--];
                st[++top] = (y / x);
            }
            else
            {
                st[++top] = (stoi(tokens.at(i)));
            }
        }
        return st[top];
    }
};