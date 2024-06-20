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

class Solution2
{
    void placeNext(int start_row, int start_col, vector<vector<vector<bool>>> &blocked, int qindex, int &nsol, int n)
    {
        // find the next right position
        for (int rrow = start_row; rrow < n; ++rrow)
        {
            for (int rcol = start_col; rcol < n; ++rcol)
            {
                bool cblocked = false;
                for (int qit = 0; !cblocked && qit < qindex; ++qit)
                {
                    cblocked |= blocked[qit][rrow][rcol];
                }
                if (!cblocked)
                {
                    if (qindex == n - 1)
                    {
                        nsol++;
                        return;
                    }
                    blocked[qindex] = vector<vector<bool>>(n, vector<bool>(n, false));
                    blockAt(qindex, rrow, rcol, n, blocked);
                    placeNext(rrow + 1, 0, blocked, qindex + 1, nsol, n);
                }
            }
        }
    }

    void blockAt(int qindex, int row, int col, int n, vector<vector<vector<bool>>> &blocked)
    {
        for (int rcol = col; rcol < n; ++rcol)
        {
            blocked[qindex][row][rcol] = true;
        }
        for (int rrow = row + 1, diag = 1; rrow < n; ++rrow, ++diag)
        {
            blocked[qindex][rrow][col] = true;
            int diagleft = col - diag;
            if (diagleft >= 0)
                blocked[qindex][rrow][diagleft] = true;
            int diagright = col + diag;
            if (diagright < n)
            {
                blocked[qindex][rrow][diagright] = true;
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        int nsol = 0;
        vector<vector<vector<bool>>> blocked(n - 1, vector<vector<bool>>(n, vector<bool>(n, false)));
        placeNext(0, 0, blocked, 0, nsol, n);
        return nsol;
    }
};

class Solution
{
    bool isBlocked(int row, int col, vector<int> &queens)
    {
        // check if position row, col is blocked by other queens
        for (int i = 0; i < queens.size(); ++i)
        {
            if (queens[i] == col)
                return true;
            if (queens[i] - i == col - row || queens[i] + i == col + row)
                return true;
        }
        return false;
    }

    void placeNext(int row, int colstart, vector<int> &queens, int &nsol, int n)
    {
        for (int col_r = colstart; col_r < n; ++col_r)
        {
            if (!isBlocked(row, col_r, queens))
            {
                if (queens.size() == n - 1)
                {
                    nsol++;
                    return;
                }
                queens.push_back(col_r);
                placeNext(row + 1, 0, queens, nsol, n);
                queens.pop_back();
            }
        }
    }

public:
    int totalNQueens(int n)
    {
        vector<int> queens; // their col
        int nsol = 0;
        placeNext(0, 0, queens, nsol, n);
        return nsol;
    }
};

class Solution4
{
    bool isBlocked(int row, int col, vector<unordered_set<int>> &blocked)
    {
        if (blocked[0].find(col) != blocked[0].end())
            return true;
        if (blocked[1].find(col + row) != blocked[1].end())
            return true;
        if (blocked[2].find(row - col) != blocked[2].end())
            return true;
        return false;
    }

    void block(int row, int col, vector<unordered_set<int>> &blocked)
    {
        blocked[0].insert(col);
        blocked[1].insert(row + col);
        blocked[2].insert(row - col);
    }

    void release(int row, int col, vector<unordered_set<int>> &blocked)
    {
        blocked[0].erase(col);
        blocked[1].erase(row + col);
        blocked[2].erase(row - col);
    }

    void placeNext(int start_row, int start_col, vector<unordered_set<int>> &blocked, int quindex, int &nsol, int n)
    {
        for (int rem_row = start_row; rem_row < n; ++rem_row)
        {
            for (int rem_col = start_col; rem_col < n; ++rem_col)
            {
                if (!isBlocked(rem_row, rem_col, blocked))
                {
                    if (quindex == n - 1)
                    {
                        nsol++;
                        return;
                    }
                    block(rem_row, rem_col, blocked);
                    placeNext(rem_row + 1, 0, blocked, quindex + 1, nsol, n);
                    release(rem_row, rem_col, blocked);
                }
            }
        }
        return;
    }

public:
    int totalNQueens(int n)
    {
        vector<unordered_set<int>> blocked(3, unordered_set<int>{}); // blocked col, diag / and diag -
        int nsol = 0;
        placeNext(0, 0, blocked, 0, nsol, n);
        return nsol;
    }
};

int main()
{
    Solution sol;
    cout << sol.totalNQueens(3);
    return 0;
}