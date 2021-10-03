// Given two strings s and t, return true if t is an anagram of s, and false otherwise.


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char, int>mp;
        for(char c: s)
        {
            mp[c]++;
        }
        for (char c: t){
            mp[c]--;
        }
        
        for(pair<char,int> p:mp){
            if(p.second!=0) return false;
        }
        return true;
    }
};
