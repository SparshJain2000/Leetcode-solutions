//Problem Statement
/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        int arr[26]={0};
        for(char c:s) arr[c-(int)'a']++;
        for(char c:t) arr[c-(int)'a']--;
        for(int i:arr) if(i) return false;
        return true;
    }
};