//Problem Statement
/*
    Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.
    We repeatedly make duplicate removals on S until we no longer can.
    Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.from the record. It is guaranteed there will always be a previous score.
    Return the sum of all the scores on the record.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char c : S)
            (!st.empty() && st.top() == c) ? st.pop() : st.push(c);
        string s = "";
        while (!st.empty()) s = st.top() + s, st.pop();
        return s;
    }
};