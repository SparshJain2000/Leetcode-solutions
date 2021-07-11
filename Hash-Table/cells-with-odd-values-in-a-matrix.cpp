//Problem Statement
/*
    There is an m x n matrix that is initialized to all 0's. There is also a 2D array indices where each indices[i] = [ri, ci] represents a 0-indexed location to perform some increment operations on the matrix.
    For each location indices[i], do both of the following:

    Increment all the cells on row ri.
    Increment all the cells on column ci.
    Given m, n, and indices, return the number of odd-valued cells in the matrix after applying the increment to all locations in indices.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>>mat(m,vector<int>(n,0));
        unordered_map<int,int>mr;
        unordered_map<int,int>mc;
        for(auto p:indices) mr[p[0]]++,mc[p[1]]++;
        int r=0,c=0;
        for(auto p:mr) r+=(p.second&1)?1:0;
        for(auto p:mc) c+=(p.second&1)?1:0;
        cout<<r<<" "<<c;
        return r*n + c*m - 2*r*c;

        
        // for(auto p:indices){
        //     int r=p[0];
        //     int c=p[1];
        //     for(int i=0;i<m;i++) mat[i][c]++;
        //     for(int i=0;i<n;i++) mat[r][i]++;
        // }
        // int ans=0;
        // for(auto x:mat)
        //     for(int i:x) ans+=(i&1)?1:0;
        // return ans;
    }
};