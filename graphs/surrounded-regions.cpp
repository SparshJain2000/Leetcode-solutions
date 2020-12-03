//Problem Statement
/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
Return the number of closed islands.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    void fill(vector<vector<char>> &board, int i, int j)
    {
        if (i >= 0 && j >= 0 && i < board.size() && j < board[0].size() && board[i][j] == 'O')
        {
            board[i][j] = 'Z';
            fill(board, i + 1, j);
            fill(board, i - 1, j);
            fill(board, i, j + 1);
            fill(board, i, j - 1);
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        if (board.size())
        {
            for (int i = 0; i < board.size(); i++)
                fill(board, i, 0), fill(board, i, board[0].size() - 1);
            for (int i = 0; i < board[0].size(); i++)
                fill(board, 0, i), fill(board, board.size() - 1, i);

            for (int i = 1; i < board.size() - 1; i++)
                for (int j = 1; j < board[i].size() - 1; j++)
                    if (board[i][j] == 'O')
                        board[i][j] = 'X';

            for (int i = 0; i < board.size(); i++)
                for (int j = 0; j < board[i].size(); j++)
                    if (board[i][j] == 'Z')
                        board[i][j] = 'O';
        }
    }
};