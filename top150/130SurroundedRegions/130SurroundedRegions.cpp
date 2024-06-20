#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
    void saveFrom(int row, int col, vector<vector<char>> &board)
    {
        auto &cell = board[row][col];
        if (cell == 'x' || cell == 's')
            return;
        cell = 's';

        if (row - 1 >= 0)
            saveFrom(row - 1, col, board);

        if (row + 1 < board.size())
            saveFrom(row + 1, col, board);

        if (col - 1 >= 0)
            saveFrom(row, col - 1, board);

        if (col + 1 < board[0].size())
            saveFrom(row, col + 1, board);
    }

public:
    void solve(vector<vector<char>> &board)
    {
        for (int row = 0; row < board.size(); ++row)
        {
            saveFrom(row, 0, board);
            saveFrom(row, board[0].size() - 1, board);
        }
        for (int col = 0; col < board[0].size(); ++col)
        {
            saveFrom(0, col, board);
            saveFrom(board.size() - 1, col, board);
        }

        for (auto &row : board)
        {
            for (auto &cell : row)
            {
                if (cell == 's')
                    cell = 'o';
                else if (cell == 'o')
                    cell = 'x';
            }
        }
    }
};

int main()
{
    vector<vector<char>> board = {{'x', 'o', 'x', 'x'}, {'x', 'o', 'o', 'x'}, {'x', 'x', 'o', 'x'}, {'x', 'o', 'x', 'x'}};
    Solution sol;
    sol.solve(board);
    for (auto row : board)
    {
        for (auto cell : row)
        {
            cout << cell;
        }
        cout << endl;
    }
    return 0;
}