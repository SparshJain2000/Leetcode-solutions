//Problem Statement
/*
Given the array queries of positive integers between 1 and m, you have to process all queries[i] (from i=0 to i=queries.length-1) according to the following rules:

In the beginning, you have the permutation P=[1,2,3,...,m].
For the current i, find the position of queries[i] in the permutation P (indexing from 0) and then move this at the beginning of the permutation P. Notice that the position of queries[i] in P is the result for queries[i].
Return an array containing the result for the given queries.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> processQueries(vector<int> &queries, int m) {
        vector<int> v(m + 1, 0);
        for (int i = 1; i <= m; i++)
            v[i] = (i - 1);
        for (int &q : queries) {
            int temp = v[q];
            for (int i = 1; i <= m; i++)
                if (v[i] < temp)
                    v[i]++;
            v[q] = 0;
            q = temp;
        }
        return queries;
    }
};