//Problem Statement
/*
You are given an array of distinct integers arr and an array of integer arrays pieces, where the integers in pieces are distinct. Your goal is to form arr by concatenating the arrays in pieces in any order. However, you are not allowed to reorder the integers in each array pieces[i].
Return true if it is possible to form the array arr from pieces. Otherwise, return false.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        map<int, int> ind;
        for (int i = 0; i < arr.size(); i++) ind[arr[i]] = i;
        for (int i = 0; i < pieces.size(); i++) {
            if (pieces[i].size() == 1 && ind.find(pieces[i][0]) == ind.end()) return false;
            for (int j = 1; j < pieces[i].size(); j++)
                if (ind[pieces[i][j]] != ind[pieces[i][j - 1]] + 1) return false;
        }
        return true;
    }
};