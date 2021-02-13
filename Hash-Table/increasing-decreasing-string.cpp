//Problem Statement
/*
Given a string s. You should re-order the string using the following algorithm:
    Pick the smallest character from s and append it to the result.
    Pick the smallest character from s which is greater than the last appended character to the result and append it.
    Repeat step 2 until you cannot pick more characters.
    Pick the largest character from s and append it to the result.
    Pick the largest character from s which is smaller than the last appended character to the result and append it.
    Repeat step 5 until you cannot pick more characters.
    Repeat the steps from 1 to 6 until you pick all characters from s.
    In each step, If the smallest or the largest character appears more than once you can choose any occurrence and append it to the result.

Return the result string after sorting s with this algorithm.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string sortString(string s) {
        int m[26] = {0};
        for (char c : s) m[c - 'a']++;
        string ans = "";
        while (ans.length() < s.length()) {
            for (int i = 0; i < 26; i++)
                if (m[i]) ans += (char)i + 'a', m[i]--;
            for (int i = 25; i >= 0; i--)
                if (m[i]) ans += (char)i + 'a', m[i]--;
        }
        return ans;
        /* using map
            map<char,int>m;
            for(char c:s) m[c]++;
            string ans="";
            while(ans.length()<s.length()){
                for(auto p:m)
                    if(p.second) ans+=p.first,m[p.first]--;
                for(auto i=m.rbegin();i!=m.rend();++i)
                    if(i->second) ans+=i->first,m[i->first]--;
            }
            return ans;
        */
    }
};