#include <bits/stdc++.h>
using namespace std;
typedef pair<string, int> pi;
typedef vector<pi> vii;
class Solution
{
public:
    string repeat(string s, int n)
    {
        string ans = "";
        while (n--)
            ans += s;
        return ans;
    }
    string decodeAtIndex(string S, int K)
    {
        long N = 0, i;
        for (i = 0; N < K; ++i)
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        while (i--)
            if (isdigit(S[i]))
                N /= S[i] - '0', K %= N;
            else if (K % N-- == 0)
                return string(1, S[i]);
        return "";
    }
};
int main()
{
    Solution s;
    cout << s.decodeAtIndex("a2b3c4d5e6f7g8h9", 41);
}