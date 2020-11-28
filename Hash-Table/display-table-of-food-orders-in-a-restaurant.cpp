//Problem Statement
/*
Given the array orders, which represents the orders that customers have done in a restaurant. More specifically orders[i]=[customerNamei,tableNumberi,foodItemi] where customerNamei is the name of the customer, tableNumberi is the table customer sit at, and foodItemi is the item customer orders.

Return the restaurant's “display table”. The “display table” is a table whose row entries denote how many of each food item each table ordered. The first column is the table number and the remaining columns correspond to each food item in alphabetical order. The first row should be a header whose first column is “Table”, followed by the names of the food items. Note that the customer names are not part of the table. Additionally, the rows should be sorted in numerically increasing order.*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<string, string> pss;
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

class Solution
{
public:
    vector<vector<string>> displayTable(vector<vector<string>> &orders)
    {
        unordered_map<pss, int, pair_hash> m;

        set<string> s;
        set<int> temp;
        s.insert("");
        for (vector<string> vs : orders)
            m[pss(vs[1], vs[2])]++, s.insert(vs[2]), temp.insert(stoi(vs[1]));

        vector<vector<string>> ans(temp.size() + 1, vector<string>(s.size(), ""));

        ans[0] = vector<string>(s.begin(), s.end());
        ans[0][0] = "Table";

        int i = 1;
        for (int a : temp)
        {
            string z = to_string(a);
            ans[i][0] = z;
            for (int j = 1; j < ans[0].size(); j++)
                ans[i][j] = to_string(m[pss(z, ans[0][j])]);
            i++;
        }

        return ans;
    }
};