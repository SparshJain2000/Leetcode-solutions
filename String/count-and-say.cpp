
//Problem Statement
/*
Given a string s formed by digits ('0' - '9') and '#' . We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively. 
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string countAndSay(int n) {
        string ans = "1";
        while (--n) {
            string temp = "";
            int j = 0;
            while (j < ans.size()) {
                int i = 0;
                char c = ans[j];
                while (j < ans.size() && c == ans[j]) i++, j++;
                temp += to_string(i) + c;
                if (!i) j++;
            }
            ans = temp;
        }
        return ans;
    }
};