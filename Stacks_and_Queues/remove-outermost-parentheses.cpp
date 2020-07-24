//Problem Statement
/*
A valid parentheses string is either empty (""), "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.  For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.

A valid parentheses string S is primitive if it is nonempty, and there does not exist a way to split it into S = A+B, with A and B nonempty valid parentheses strings.

Given a valid parentheses string S, consider its primitive decomposition: S = P_1 + P_2 + ... + P_k, where P_i are primitive valid parentheses strings.

Return S after removing the outermost parentheses of every primitive string in the primitive decomposition of S.    
*/
#include <bits/stdc++.h>
class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        int k = 0;
        int start = 0;
        string ans = "";
        for (int i = 0; i < S.length(); i++)
        {
            (S[i] == '(') ? k++ : k--;
            if (!k)
            {
                ans += S.substr(start + 1, i - start - 1);
                start = i + 1;
            }
        }
        return ans;
    }
};