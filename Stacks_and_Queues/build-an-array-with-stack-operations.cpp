//Problem Statement
/*
    Given an array target and an integer n. In each iteration, you will read a number from  list = {1,2,3..., n}.
    Build the target array using the following operations:
    Push: Read a new element from the beginning list, and push it in the array.
    Pop: delete the last element of the array.

    If the target array is already built, stop reading more elements.
    Return the operations to build the target array. You are guaranteed that the answer is unique.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int j = 0, i = 1;
        while (i <= n && j < target.size()) {
            for (int k = 0; k < target[j] - i; k++) {
                ops.push_back("Push");
                ops.push_back("Pop");
            }
            ops.push_back("Push");
            i = ++target[j++];
        }
        return ops;
    }
};