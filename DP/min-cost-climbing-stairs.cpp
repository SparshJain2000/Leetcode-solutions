//Problem Statement
/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // f(0)=cost[0];
        // f(1)=cost[1];
        // f(2)=cost[2]+min(f(0),f(1));
        // f(i)=cost(i) + min(f(i+1),f(i+2))
        int f1=0,f0=0;
        for(int i=0;i<cost.size();i++){
            int temp=f1;
            f1=cost[i]+min(f0,f1);
            f0=temp;
        }
        return min(f0,f1);
    }
};