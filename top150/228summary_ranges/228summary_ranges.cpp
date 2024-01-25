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
    vector<vector<int>> summaryRanges(vector<int> nums)
    {
        vector<vector<int>> ret;
        if (nums.size() == 1)
        {
            ret.push_back(vector<int>{nums[0], nums[0]});
            return ret;
        }
        int behind = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] - 1 != nums[i - 1])
            {
                ret.push_back(vector<int>{behind, nums[i - 1]});
                behind = nums[i];
            }
            if (i == nums.size() - 1)
            {
                ret.push_back(vector<int>{behind, nums.back()});
            }
        }
        return ret;
    }

    void printSummary(vector<vector<int>> &arr)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            cout << arr[i][0] << "," << arr[i][1];
            cout << endl;
        }
    }
};

int main()
{
    Solution solution;

    // Test Case 1
    // auto vec = vector<int>{0, 1, 2, 4, 5, 7};
    auto vec = vector<int>{0, 2, 3, 4, 6, 8, 9};
    auto ret = solution.summaryRanges(vec);
    solution.printSummary(ret);

    return 0;
}
