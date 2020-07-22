//Problem Statement
/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A"
*/
#include <bits/stdc++.h>
class Solution
{
public:
    int numJewelsInStones(string J, string S)
    {
        int arr[128] = {0};
        for (char c : S)
        {
            arr[c]++;
        }
        int a = 0;
        for (char c : J)
        {
            if (arr[c])
                a += arr[c];
        }
        return a;
    }
};