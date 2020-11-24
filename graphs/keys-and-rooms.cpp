//Problem Statement
/*
There are N rooms and you start in room 0.  Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room. 
Formally, each room i has a list of keys rooms[i], and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.  A key rooms[i][j] = v opens the room with number v.
Initially, all the rooms start locked (except for room 0). 
You can walk back and forth between rooms freely.
Return true if and only if you can enter every room.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
class Solution
{
    void dfs(vii rooms, int s, vi &vis)
    {
        if (!vis[s])
        {
            vis[s] = 1;
            for (int i : rooms[s])
                if (!vis[i])
                    dfs(rooms, i, vis);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        vi vis(rooms.size(), 0);
        dfs(rooms, 0, vis);
        bool ans = true;
        for (int i : vis)
            ans &= i;
        return ans;
    }
};