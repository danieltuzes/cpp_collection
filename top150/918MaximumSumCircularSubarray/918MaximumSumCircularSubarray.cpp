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
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int summax = 0;
        int maxim = numeric_limits<int>::min();

        int summin = 0;
        int minim = numeric_limits<int>::max();

        int glob_sum = 0;

        for (int i = 0; i < nums.size(); ++i)
        {
            summax += nums[i];
            maxim = max(maxim, summax);
            summax = max(0, summax);

            summin += nums[i];
            minim = min(minim, summin);
            summin = min(0, summin);

            glob_sum += nums[i];
        }
        if (glob_sum == minim)
            return maxim;
        int o_b_max = glob_sum - minim;
        maxim = max(maxim, o_b_max);
        return maxim;
    }
};

int main()
{
    vector<int> nums{5, -3, 5};
    Solution sol;
    cout << sol.maxSubarraySumCircular(nums);
}