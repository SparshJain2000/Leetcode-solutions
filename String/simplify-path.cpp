//Problem Statement
/*
Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level.

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path. 
*/
#include <bits/stdc++.h>
class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> ans;
        vector<string> dir;
        char file[path.length() + 1];
        strcpy(file, path.c_str());
        char x[] = {'/'};
        char *token = strtok(file, x);
        while (token != NULL)
        {
            dir.push_back(string(token));
            token = strtok(NULL, x);
        }

        for (int i = 0; i < dir.size(); i++)
        {
            if (dir.at(i) == "..")
            {
                if (ans.size() != 0)
                {
                    ans.pop_back();
                    // cout << ans.top() << " ";
                }
            }
            else if (dir.at(i) != ".")
            {
                ans.push_back(dir.at(i));
                // cout << ans.top() << " ";
            }
        }
        if (ans.size() == 0)
            return "/";
        string answer = "";
        for (int i = 0; i < ans.size(); i++)
        {
            answer += "/" + ans.at(i);
        }
        return answer;
    }
};