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
    int maxSubArray(vector<int> &nums)
    {
        int maxval = nums[0];
        int currentSum = 0;
        for (int num : nums)
        {
            currentSum = max(num, currentSum + num);
            maxval = max(maxval, currentSum);
        }
        return maxval;
    }
};

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int summ = 0;
        int maxim = numeric_limits<int>::min();
        for (int i = 0; i < nums.size(); ++i)
        {
            summ += nums[i];
            maxim = max(maxim, summ);
            summ = max(0, summ);
        }
        return maxim;
    }
};

int main()
{
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
}