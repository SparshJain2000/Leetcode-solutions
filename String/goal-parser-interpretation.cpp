//Problem Statement
/*
    You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.
    Given the string command, return the Goal Parser's interpretation of command.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string interpret(string command) {
        int i = 0;
        int n = command.size();
        while (i < n) {
            if (command[i] == 'G')
                command += "G";
            else if (command[i] == '(' && command[i + 1] == ')')
                command += "o", i++;
            else
                command += "al", i += 3;
            i++;
        }
        return string(command.begin() + n, command.end());
    }
};