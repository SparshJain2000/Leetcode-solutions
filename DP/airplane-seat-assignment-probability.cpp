//Problem Statement
/*
n passengers board an airplane with exactly n seats. The first passenger has lost the ticket and picks a seat randomly. But after that, the rest of passengers will:

Take their own seat if it is still available, 
Pick other seats randomly when they find their seat occupied 
What is the probability that the n-th person can get his own seat?
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vii;
class Solution
{
public:
    double nthPersonGetsNthSeat(int n)
    {
        return (n == 1 ? (double)1 : (double).5);
    }
};
