//Problem Statement
/*
    Let's play the minesweeper game (Wikedia, online game)!
    You are given a 2D char matrix reprenting the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.
    Now given the next click position (r and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:
    If a mine ('M') is revealed, then thgame is over - change it to 'X'.
    If an empty square ('E') with no adjent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
    If an empty square ('E') with at lea one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
    Return the board when no more squarewill be revealed.
*/
#include <bits/stdc++.h>
using namespace std;
typedef vector<char> vc;
typedef vector<vc> vcc;
class Solution
{
    int rsize;
    int csize;
    vector<int> dir{1, 0, -1, 0, 1, 1, -1, -1, 1};
    bool valid(int i, int j)
    {
        return i >= 0 && j >= 0 && i < rsize && j < csize;
    }
    void util(vcc &board, int i, int j)
    {
        if (valid(i, j) && board[i][j] == 'E')
        {
            int adj = 0;
            for (int k = 0; k < dir.size() - 1; k++)
                adj += valid(i + dir[k], j + dir[k + 1]) && board[dir[k] + i][j + dir[k + 1]] == 'M';
            if (adj)
                board[i][j] = '0' + adj;
            else
            {
                board[i][j] = 'B';
                for (int k = 0; k < dir.size() - 1; k++)
                    util(board, i + dir[k], j + dir[k + 1]);
            }
        }
    }

public:
    vcc updateBoard(vcc &board, vector<int> &click)
    {
        if (!board.size())
            return board;
        this->rsize = board.size();
        this->csize = board[0].size();
        if (board[click[0]][click[1]] == 'M')
            board[click[0]][click[1]] = 'X';
        else if (board[click[0]][click[1]] == 'E')
            util(board, click[0], click[1]);
        return board;
    }
};