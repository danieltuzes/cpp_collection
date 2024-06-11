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
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i)
        {
            dp[i][0] = matrix[i][0] == '0' ? 0 : 1;
        }
        for (int i = 0; i < matrix[0].size(); ++i)
        {
            dp[0][i] = matrix[0][i] == '0' ? 0 : 1;
        }
        for (int i = 1; i < matrix.size(); ++i)
        {
            for (int j = 1; j < matrix[0].size(); ++j)
            {
                dp[i][j] = matrix[i][j] == '1' ? min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1 : 0;
            }
        }
        int maxSq = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                maxSq = max(maxSq, dp[i][j]);
            }
        }
        return maxSq * maxSq;
    }
};

class Solution2
{
    int maxLoc(vector<vector<char>> &matrix, int i, int j)
    {
        if (matrix[i][j] == '0')
            return 0;

        int max_sq = 1;
        for (; i + max_sq < matrix.size() && j + max_sq < matrix[0].size(); ++max_sq)
        {
            for (int col = j; col < max_sq + j + 1; ++col)
            {
                if (matrix[i + max_sq][col] != '1')
                    return max_sq;
            }
            for (int row = i; row < i + max_sq; ++row)
            {
                if (matrix[row][j + max_sq] != '1')
                    return max_sq;
            }
        }
        return max_sq * max_sq;
    }

public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int longest = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                longest = max(longest, maxLoc(matrix, i, j));
                if (j + longest + 1 > matrix[0].size())
                    continue;
            }
            if (i + longest + 1 > matrix.size())
                continue;
        }
        return longest * longest;
    }
};

int main()
{
    // vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    vector<vector<char>> matrix1 = {{'0'}};
    vector<vector<char>> matrix2 = {{'1'}};
    vector<vector<char>> matrix3 = {{'1', '0'}, {'1', '0'}};
    vector<vector<char>> matrix4 = {{'1', '1'}, {'1', '1'}};
    vector<vector<char>> matrix5 = {{'0', '0', '0'}, {'0', '1', '1'}, {'0', '1', '1'}};
    vector<vector<char>> matrix6 = {{'0', '1'}, {'1', '0'}};
    vector<vector<char>> matrix7 = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    Solution sol;
    cout << sol.maximalSquare(matrix1) << endl;
    cout << sol.maximalSquare(matrix2) << endl;
    cout << sol.maximalSquare(matrix3) << endl;
    cout << sol.maximalSquare(matrix4) << endl;
    cout << sol.maximalSquare(matrix5) << endl;
    cout << sol.maximalSquare(matrix6) << endl;
    cout << sol.maximalSquare(matrix7) << endl;
    return 0;
}