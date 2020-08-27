//Problem Statement
/*
Write a class RecentCounter to count recent requests.

It has only one method: ping(int t), where t represents some time in milliseconds.

Return the number of pings that have been made from 3000 milliseconds ago until now.

Any ping with time in [t - 3000, t] will count, including the current ping.

It is guaranteed that every call to ping uses a strictly larger value of t than before.
*/
#include <bits/stdc++.h>
class RecentCounter
{
    queue<int> q;

public:
    RecentCounter()
    {
    }
    int ping(int t)
    {
        q.push(t);
        while (q.back() - q.front() > 3000)
            q.pop();
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */