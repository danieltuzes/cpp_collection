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
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.back().back() == 1 || obstacleGrid.front().front() == 1)
            return 0;
        obstacleGrid[0][0] = -1;
        for (int row = 0; row < obstacleGrid.size(); ++row)
        {
            for (int col = 0; col < obstacleGrid[0].size(); ++col)
            {
                if (obstacleGrid[row][col] == 1)
                    continue;
                if (row - 1 >= 0 && obstacleGrid[row - 1][col] < 0)
                    obstacleGrid[row][col] += obstacleGrid[row - 1][col];

                if (col - 1 >= 0 && obstacleGrid[row][col - 1] < 0)
                    obstacleGrid[row][col] += obstacleGrid[row][col - 1];
            }
        }

        return -obstacleGrid.back().back();
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution sol;
    cout << sol.uniquePathsWithObstacles(grid);
    return 0;
}