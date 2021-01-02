//Problem Statement
/*
Given a list of lists of integers, nums, return all elements of nums in diagonal order as shown in the below images.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
   public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0) return ans;
        /*
            Nāive approach(traverse the matrix matrix.size()*max(columne(matrix)) times)
                int n = matrix.size();
                int m = 0;
                for(vector<int>v:matrix) if(m<v.size()) m=v.size();
                for (int i = 0; i < m; i++) {
                    int c = 0;
                    int k = 0;
                    int cur_size = ans.size();
                    while (i - c >= 0 && k + c < n){
                        if(i-c<matrix[k+c].size()) ans.push_back(matrix[k + c][i - c]);
                        c++;
                    }

                    reverse(ans.begin() + cur_size, ans.end());
                }
                for (int i = 1; i < n; i++) {
                    int c = 0;
                    int j = m - 1;
                    int cur_size = ans.size();
                    while (j - c >= 0 && i + c < n){
                        if(j-c<matrix[i+c].size()) ans.push_back(matrix[i + c][j - c]);
                        c++;
                    }
                    reverse(ans.begin() + cur_size, ans.end());
                }

        */
        //storing in map by sum of row and column as key
        unordered_map<int, vector<int>> m;
        int mi = 0;
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                m[i + j].push_back(matrix[i][j]), mi = max(mi, i + j);

        for (int i = 0; i <= mi; i++)
            for (int j = m[i].size() - 1; j >= 0; j--)
                ans.push_back(m[i][j]);

        return ans;
    }
};
