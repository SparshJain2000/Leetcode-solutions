//Problem Statement
/*
Given two strings representing two complex numbers.
You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
class Solution
{
    vs split(string s, char delim)
    {
        vs ans;
        istringstream iss(s);
        string item;
        while (getline(iss, item, delim))
            ans.push_back(item);
        return ans;
    }

public:
    string complexNumberMultiply(string a, string b)
    {
        vs as = split(a, '+');
        vs bs = split(b, '+');
        int real = stoi(as[0]) * stoi(bs[0]) - stoi(as[1]) * stoi(bs[1]);
        int complex = stoi(as[1]) * stoi(bs[0]) + stoi(bs[1]) * stoi(as[0]);
        return to_string(real) + "+" + to_string(complex) + "i";
    }
};
