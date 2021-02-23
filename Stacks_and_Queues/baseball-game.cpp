//Problem Statement
/*
    You are keeping score for a baseball game with strange rules. The game consists of several rounds, where the scores of past rounds may affect future rounds' scores.
    At the beginning of the game, you start with an empty record. You are given a list of strings ops, where ops[i] is the ith operation you must apply to the record and is one of the following:

    An integer x - Record a new score of x.
    "+" - Record a new score that is the sum of the previous two scores. It is guaranteed there will always be two previous scores.
    "D" - Record a new score that is double the previous score. It is guaranteed there will always be a previous score.
    "C" - Invalidate the previous score, removing it from the record. It is guaranteed there will always be a previous score.
    Return the sum of all the scores on the record.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for (string str : ops) {
            if (str == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                s.push(a + b);
            } else if (str == "D") {
                s.push(s.top() * 2);
            } else if (str == "C")
                s.pop();
            else
                s.push(stoi(str));
        }
        int ans = 0;
        while (!s.empty()) ans += s.top(), s.pop();
        return ans;
    }
};