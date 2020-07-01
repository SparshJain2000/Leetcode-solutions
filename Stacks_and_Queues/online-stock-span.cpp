//Problem Statement
/*
Write a class StockSpanner which collects daily price quotes for some stock, and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backwards) for which the price of the stock was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100, 80, 60, 70, 60, 75, 85], then the stock spans would be [1, 1, 1, 2, 1, 4, 6].
*/

#include <bits/stdc++.h>
class StockSpanner
{
    stack<pair<int, int>> s;

public:
    StockSpanner()
    {
        s = stack<pair<int, int>>();
    }
    int next(int price)
    {
        int wt = 1;
        while (!s.empty() && price >= s.top().first)
        {
            wt += s.top().second;
            s.pop();
        }
        s.push(pair<int, int>(price, wt));
        return s.top().second;
    }
};