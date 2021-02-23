//Problem Statement
/*
    You are given the array paths, where paths[i] = [cityAi, cityBi] means there exists a direct path going from cityAi to cityBi. Return the destination city, that is, the city without any path outgoing to another city.

    It is guaranteed that the graph of paths forms a line without any loop, therefore, there will be exactly one destination city.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    string destCity(vector<vector<string>>& paths) {
        //USING UNORDERED_MAP WITH 2 STRING
        /*
            unordered_map<string, int> m;
            int i = 0;
            for (vector<string> v : paths) m[v[0]] = i++;
            string x = paths[0][0];
            while (true) {
                if (m.find(x) == m.end()) return x;
                x = paths[m[x]][1];
            }
        */
        //using unordered map with strings and their index of paths and iterating paths.
        unordered_map<string, int> m;
        int i = 0;
        for (int i = 0; i < paths.size(); i++) m[paths[i][0]] = i;
        string x = paths[0][0];
        while (true) {
            if (m.find(x) == m.end()) return x;
            x = paths[m[x]][1];
        }

        //using unordered map and set : extra space less time
        /*
            unordered_map<string, int> m;
            set<string> s;
            for(int i=0;i<paths.size();i++) m[paths[i][0]]=i,s.insert(paths[i][0]),s.insert(paths[i][1]);
            for (string str : s)
                if (m.find(str) == m.end()) return str;
            return "";
        */
    }
};