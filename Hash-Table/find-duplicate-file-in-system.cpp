//Problem Statement
/*
Given a list of directory info including directory path, and all the files with contents in this directory, you need to find out all the groups of duplicate files in the file system in terms of their paths.
A group of duplicate files consists of at least two files that have exactly the same content.
A single directory info string in the input list has the following format:
"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
It means there are n files (f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) in directory root/d1/d2/.../dm. Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.
The output is a list of group of duplicate file paths. For each group, it contains all the file paths of the files that have the same content. A file path is a string that has the following format:
"directory_path/file_name.txt"
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vs> vss;

class Solution
{
    vs split(string s, char delim)
    {
        vs ans;
        istringstream iss(s);
        string item;
        while (getline(iss, item, delim))
            ans.push_back(item);
        return ans;
    }

public:
    vector<vector<string>> findDuplicate(vector<string> &paths)
    {
        unordered_map<string, vs> m;
        for (string s : paths)
        {
            auto strs = split(s, ' ');
            for (int i = 1; i < strs.size(); i++)
            {
                vs qs = split(strs[i], '(');
                m[qs[1].substr(0, qs[1].length() - 1)].push_back(strs[0] + "/" + qs[0]);
            }
        }
        vss ans;
        for (auto p : m)
            if (p.second.size() > 1)
                ans.push_back(p.second);
        return ans;
    }
};