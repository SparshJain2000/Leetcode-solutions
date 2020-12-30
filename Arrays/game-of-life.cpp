//Problem Statement
/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
    Any live cell with fewer than two live neighbors dies as if caused by under-population.
    Any live cell with two or three live neighbors lives on to the next generation.
    Any live cell with more than three live neighbors dies, as if by over-population.
    Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
    The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
    int n, m;
    vector<int> dir{1, 0, -1, 0, 1, 1, -1, -1, 1};
    bool isValid(int i, int j) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int neigh(vector<vector<int>>& board, int i, int j) {
        int ans = 0;
        for (int k = 0; k < dir.size() - 1; k++)
            ans += isValid(i + dir[k], j + dir[k + 1]) && board[i + dir[k]][j + dir[k + 1]];
        return ans;
    }

   public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> grid = board;
        n = board.size();
        m = board[0].size();
        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++) {
                int neighbours = neigh(board, i, j);
                if (neighbours < 2 || neighbours > 3)
                    grid[i][j] = 0;
                else if (neighbours == 3)
                    grid[i][j] = 1;
            }
        board = grid;
    }
};