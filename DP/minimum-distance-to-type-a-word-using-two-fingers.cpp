//Problem Statement
/*
You have a keyboard layout as shown above in the XY plane, where each English uppercase letter is located at some coordinate, for example, the letter A is located at coordinate (0,0), the letter B is located at coordinate (0,1), the letter P is located at coordinate (2,3) and the letter Z is located at coordinate (4,1).

Given the string word, return the minimum total distance to type such string using only two fingers. The distance between coordinates (x1,y1) and (x2,y2) is |x1 - x2| + |y1 - y2|. 

Note that the initial positions of your two fingers are considered free so don't count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef vector<pi> vii;
class Solution
{
public:
    int dist(pi p1, pi p2)
    {
        return abs(p1.first - p2.first) + abs(p1.second - p2.second);
    }
    vii v;
    int minimumDistance(string word)
    {
        for (int i = 0; i < 27; i++)
        {
            int y = i % 6;
            int x = i / 6;
            v.push_back(pi(x, y));
        }
        int dp[word.length() + 1][27][27];
        for (int i = 0; i < word.length() + 1; i++)
        {
            for (int j = 0; j < 27; j++)
                for (int k = 0; k < 27; k++)
                    dp[i][j][k] = 0;
        }
        for (int i = word.length() - 1; i >= 0; i--)
        {
            for (int j = 0; j < 27; j++)
            {
                for (int k = 0; k < 27; k++)
                {
                    dp[i][j][k] =
                        min(dp[i + 1][word[i] - 'A'][k] + (j == 26 ? 0 : dist(v[word[i] - 'A'], v[j])),
                            dp[i + 1][j][word[i] - 'A'] + (k == 26 ? 0 : dist(v[word[i] - 'A'], v[k])));
                }
            }
        }
        return dp[0][26][26];
    }
};