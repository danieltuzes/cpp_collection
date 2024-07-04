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
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int left = 0;
        int right = matrix.size() - 1;
        for (int center = (left + right) / 2; left <= right;)
        {
            if (matrix[center][0] > target)
                right = center - 1;
            else if (matrix[center][0] < target)
                left = center + 1;
            else
            {
                right = center;
                break;
            }
            center = (left + right) / 2;
        }
        if (right == -1)
            return false;
        int row = right;

        left = 0;
        right = matrix[0].size() - 1;
        for (int center = (left + right) / 2; left <= right;)
        {
            if (matrix[row][center] < target)
                left = center + 1;
            else if (matrix[row][center] > target)
                right = center - 1;
            else
                return true;
            center = (left + right) / 2;
        }

        return false;
    }
};

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int left = 0;
        int right = matrix.size() - 1;
        for (; left <= right;)
        {
            int c = (right + left) / 2;
            if (matrix[c][0] < target)
            {
                left = c + 1;
            }
            else if (matrix[c][0] > target)
            {
                right = c - 1;
            }
            else
            {
                right = c;
                break;
            }
        }
        int r = right;
        if (r < 0)
            return false;

        left = 0;
        right = matrix[0].size() - 1;
        for (; right >= left;)
        {
            int c = (right + left) / 2;
            if (matrix[r][c] < target)
            {
                left = c + 1;
            }
            else if (matrix[r][c] > target)
            {
                right = c - 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    Solution sol;
    cout << sol.searchMatrix(matrix, 0);
    cout << sol.searchMatrix(matrix, 1);
    cout << sol.searchMatrix(matrix, 7);
    cout << sol.searchMatrix(matrix, 10);
    cout << sol.searchMatrix(matrix, 12);
    cout << sol.searchMatrix(matrix, 20);
    cout << sol.searchMatrix(matrix, 22);
    cout << sol.searchMatrix(matrix, 23);
    cout << sol.searchMatrix(matrix, 30);
    cout << sol.searchMatrix(matrix, 60);
    cout << sol.searchMatrix(matrix, 65);
    return 0;
}