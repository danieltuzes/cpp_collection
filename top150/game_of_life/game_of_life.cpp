#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // for every line by index
        int m = board.size();
        int n = board[0].size();
        for (int i=0; i<m; ++i)
        {
            // for every cell by index
            for (int j=0; j<n; ++j)
            {
                // if it is live
                if (board[i][j] % 10)
                {
                    if (j-1 >= 0) board[i][j-1] +=10;
                    if (j+1 < n) board[i][j+1] +=10;
                    if (i-1 >= 0) board[i-1][j] +=10;
                    if (i+1 < m) board[i+1][j] +=10;


                    if (j-1 >= 0 && i-1 >= 0) board[i-1][j-1] +=10;
                    if (j+1 < n && i-1 >= 0) board[i-1][j+1] +=10;
                    if (j-1 >= 0 && i+1 < m) board[i+1][j-1] +=10;
                    if (j+1 < n && i+1 < m) board[i+1][j+1] +=10;
                }
            }
        }

        // for every line
        for (auto& line : board)
        {
            // for every cell
            for (auto& val : line)
            {
                int neigh = val/10;
                // if live
                if (val % 10)
                {
                    // if and number of living neighbors rule to stay alive
                    if (neigh == 2 || neigh == 3)
                        val = 1;
                    else // to die
                        val = 0;
                }
                // if dead
                // if and number of dead neighbors rule to become alive
                else if
                    (neigh == 3) val = 1;
                else
                    val = 0;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,1},{1,0}};
    s.gameOfLife(matrix);
    cout << matrix[0][1];
}