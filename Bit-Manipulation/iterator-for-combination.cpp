//Problem Statement
/*
There is a room with n bulbs, numbered from 0 to n-1, arranged in a row from left to right. Initially all the bulbs are turned off.
Your task is to obtain the configuration represented by target where target[i] is '1' if the i-th bulb is turned on and is '0' if it is turned off.
You have a switch to flip the state of the bulb, a flip operation is defined as follows:

Choose any bulb (index i) of your current configuration.
Flip each bulb from index i to n-1.
When any bulb is flipped it means that if it is 0 it changes to 1 and if it is 1 it changes to 0.
Return the minimum number of flips required to form target.
*/
#include <bits/stdc++.h>
using namespace std;
class CombinationIterator {
    int combinationLength;
    set<string> perms;
    set<string>::iterator itr;

    void gen(string s) {
        int mask = 1 << s.length();
        string comString = "";
        for (int no = 1; no < mask; no++) {
            int num = no, i = 0;
            while (num) {
                if (num & 1)
                    comString = comString + s[i];
                i++, num >>= 1;
            }
            if (comString.length() == combinationLength)
                perms.insert(comString);
            comString = "";
        }
    }

   public:
    CombinationIterator(string characters, int combinationLength) {
        this->combinationLength = combinationLength;
        gen(characters);
        itr = perms.begin();
    }

    string next() {
        return *(itr++);
    }

    bool hasNext() {
        return itr != perms.end();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
