//Problem Statement
/*
You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.

Return true if a and b are alike. Otherwise, return false.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    bool isVowel(char ch) {
        return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') ||
               (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U');
    }

   public:
    bool halvesAreAlike(string s) {
        int i = 0, j = s.length() / 2;
        int x = 0;
        while (j < s.length())
            x += isVowel(s[i++]) - isVowel(s[j++]);
        return x == 0;
    }
};