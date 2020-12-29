//Problem Statement
/*
Given a non-empty string containing only digits, determine the total number of ways to decode it.
The answer is guaranteed to fit in a 32-bit integer
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n+1);
        
        dp[0]=1;
        dp[1]=s[0]=='0'?0:1;
        for(int i=2;i<=n;i++){
            int f=stoi(s.substr(i-1,1));
            int sec=stoi(s.substr(i-2,2));
            // cout<<f<<" "<<sec<<endl;
            if(f>0 && f<10) dp[i]+=dp[i-1]; 
            if(sec>9 && sec<27) dp[i]+=dp[i-2];
        }
        return dp[n];
    }
};