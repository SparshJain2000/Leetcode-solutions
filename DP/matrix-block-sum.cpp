//Problem Statement
/*
Given a m * n matrix mat and an integer K, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, and (r, c) is a valid position in the matrix.

*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
    int lim(int n){
        if(n<0) return 0;
        return n;
    }
    int lim(int n,int size){
        if(n<0) return 0;
        if(n>=size)return size-1;
        return n;
    }
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        
        for(int i=0;i<=lim(K,m);i++){
            for(int j=0;j<=lim(K,n);j++){
                ans[0][0]+=mat[i][j];
            }
        }
        for(int i=0;i<m;i++){
            if(i){
                int g=ans[i-1][0];
                if(lim(i-K-1)<lim(i-K)){
                    for(int w=0;w<=lim(K,n);w++){
                        g-=mat[i-K-1][w];
                    }
                }
                if(i+K<m)
                for(int w=0;w<=lim(K,n);w++){
                    g+=mat[i+K][w];
                }
                ans[i][0]=g;
            }
            //================================================
            
            for(int j=1;j<n;j++){
                int z=ans[i][j-1];
                if(lim(j-K-1)<lim(j-K)){
                    for(int w=lim(i-K);w<=lim(i+K,m);w++){
                        z-=mat[w][j-K-1];
                    }
                }
                if(j+K<n)
                for(int w=lim(i-K);w<=lim(i+K,m);w++){
                    z+=mat[w][j+K];
                }
                ans[i][j]=z;
            }
        }
        return ans;
    }
};