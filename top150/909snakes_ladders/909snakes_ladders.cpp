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
    int n;

public:
    int &at(vector<vector<int>> &board, int square)
    {
        int row = n - square / n - 1;
        int col = square % n;
        if ((row + n) % 2 == 0)
            col = n - col - 1;
        return board[row][col];
    }

    bool visited(vector<vector<int>> &board, int square)
    {
        if (abs(at(board, square)) > 32 * 32)
            return true;
        return false;
    }

    void visit(vector<vector<int>> &board, int square)
    {
        int curr = at(board, square);
        if (curr > 0)
            at(board, square) += 32 * 32;
        else
            at(board, square) -= 32 * 32;
    }

    int snakesAndLadders(vector<vector<int>> &board)
    {
        n = board.size();
        queue<int> positions;
        positions.push(0);
        visit(board, 0);
        int steps = 0;
        for (; !positions.empty();)
        {
            int length = positions.size();
            ++steps;
            for (int i = 0; i < length; ++i)
            {
                int curr = positions.front();
                positions.pop();
                for (int i = 1; i < 7; ++i)
                {
                    int next_m = curr + i;
                    if (next_m >= n * n)
                        continue;

                    int next_v = at(board, next_m);
                    if (next_v > 0)
                        next_m = next_v % (32 * 32) - 1;

                    if (next_m == n * n - 1)
                        return steps;

                    if (!visited(board, next_m))
                    {
                        positions.push(next_m);
                        visit(board, next_m);
                    }
                }
            }
        }
        return -1;
    }
};
int main()
{
    vector<vector<int>> board =
        // {{-1, -1, -1, -1, -1, -1},
        //  {-1, -1, -1, -1, -1, -1},
        //  {-1, -1, -1, -1, -1, -1},
        //  {-1, 35, -1, -1, 13, -1},
        //  {-1, -1, -1, -1, -1, -1},
        //  {-1, 15, -1, -1, -1, -1}};
        // {{-1, 7, -1}, {-1, 6, 9}, {-1, -1, 2}};
        {{-1, -1, -1, 46, 47, -1, -1, -1}, {51, -1, -1, 63, -1, 31, 21, -1}, {-1, -1, 26, -1, -1, 38, -1, -1}, {-1, -1, 11, -1, 14, 23, 56, 57}, {11, -1, -1, -1, 49, 36, -1, 48}, {-1, -1, -1, 33, 56, -1, 57, 21}, {-1, -1, -1, -1, -1, -1, 2, -1}, {-1, -1, -1, 8, 3, -1, 6, 56}};
    Solution sol;
    cout << sol.snakesAndLadders(board);
    return 0;
}
