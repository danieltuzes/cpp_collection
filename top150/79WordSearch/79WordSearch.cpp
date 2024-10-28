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
    bool canFind(vector<vector<char>> &matrix, string &word, int pos, int row, int col)
    {
        if (pos == word.size()) // completed search
            return true;
        if (row == matrix.size() || row < 0)
            return false;
        if (col == matrix[0].size() || col < 0)
            return false;
        if (word[pos] != matrix[row][col])
            return false;

        char curr = matrix[row][col];
        matrix[row][col] = '-';
        bool restfind = false;
        restfind |= canFind(matrix, word, pos + 1, row, col + 1);
        restfind |= canFind(matrix, word, pos + 1, row + 1, col);
        restfind |= canFind(matrix, word, pos + 1, row, col - 1);
        restfind |= canFind(matrix, word, pos + 1, row - 1, col);
        matrix[row][col] = curr;
        return restfind;
    }

public:
    bool wordSearch(vector<vector<char>> &matrix, string word)
    {
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (canFind(matrix, word, 0, i, j))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<char>> matrix = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    vector<string> words = {"ABCCED", "SEE", "ABCB"};
    Solution sol;
    for (auto word : words)
        cout << sol.wordSearch(matrix, word);
}