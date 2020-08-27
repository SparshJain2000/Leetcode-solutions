//Problem Statement
/*
On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).
Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int climbStairs(int n)
    {
        // f(1)=>1;
        // f(2)=>2;
        // f(3)=>f(1)+f(2);
        // f(4)=>f(3)+f(2);
        int f1 = 1, f2 = 2;
        if (n == 1)
            return f1;
        if (n == 2)
            return f2;
        for (int i = 3; i <= n; i++)
        {
            int temp = f2;
            f2 = f2 + f1;
            f1 = temp;
        }
        return f2;
    }
};