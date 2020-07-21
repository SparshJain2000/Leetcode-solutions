
//Problem Statement
/*
You are driving a vehicle that has capacity empty seats initially available for passengers.  The vehicle only drives east (ie. it cannot turn around and drive west.)

Given a list of trips, trip[i] = [num_passengers, start_location, end_location] contains information about the i-th trip: the number of passengers that must be picked up, and the locations to pick them up and drop them off.  The locations are given as the number of kilometers due east from your vehicle's initial location.

Return true if and only if it is possible to pick up and drop off all passengers for all the given trips. 
*/
#include <bits/stdc++.h>
class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
        map<int, vector<pair<int, int>>> M;

        for (auto i : trips)
        {
            M[i[1]].push_back({0, i[0]});
            M[i[2]].push_back({1, i[0]});
        }

        int current_capacity = 0;
        for (auto it = M.begin(); it != M.end(); it++)
        {
            for (auto it2 : it->second)
            {
                if (it2.first == 0)
                {
                    current_capacity += it2.second;
                }
                else
                {
                    current_capacity -= it2.second;
                }
            }
            if (current_capacity > capacity)
            {
                return false;
            }
        }
        return true;
    }
};