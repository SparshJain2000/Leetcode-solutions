//Problem Statement
/*
Given an array of strings, group anagrams together.
*/
#include <bits/stdc++.h>
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        vector<vector<int>> alps;
        for (int i = 0; i < strs.size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < 26; j++)
            {
                temp.push_back(0);
            }
            for (int j = 0; j < strs.at(i).size(); j++)
            {
                temp.at((int)strs.at(i).at(j) - (int)'a')++;
            }
            bool flag = false;
            int j = 0;
            for (j = 0; j < alps.size(); j++)
            {
                if (temp == alps.at(j))
                {
                    flag = true;
                    ans.at(j).push_back(strs.at(i));
                    break;
                }
            }
            if (!flag)
            {
                alps.push_back(temp);
                vector<string> x;
                x.push_back(strs.at(i));
                ans.push_back(x);
            }
        }
        return ans;
    }
};