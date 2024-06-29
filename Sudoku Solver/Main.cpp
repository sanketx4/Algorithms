#include <bits/stdc++.h>
using namespace std;

bool issafe(int row, int col, char ch, vector<vector<char>> board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == ch)
            return false;
        if (board[i][col] == ch)
            return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            return false;
    }
    return true;
}
bool solver(int row, int col, vector<vector<char>> &board)
{
    if (row == 9)
    {
        return true;
    }
    if (col < 9)
    {
        if (board[row][col] != '.')
        {
            return solver(row, col + 1, board);
        }
        else
        {
            for (char ch = '1'; ch <= '9'; ch++)
            {
                if (issafe(row, col, ch, board))
                {
                    board[row][col] = ch;
                    if (solver(row, col + 1, board))
                        return true;
                    board[row][col] = '.';
                }
            }
        }
    }
    else if (solver(row + 1, 0, board))
        return true;
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    solver(0, 0, board);
}