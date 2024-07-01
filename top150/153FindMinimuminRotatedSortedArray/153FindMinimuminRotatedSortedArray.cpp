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
    int findMin(vector<int> &nums)
    {
        if (nums.front() <= nums.back())
            return nums.front();

        int left = 0;
        int right = nums.size() - 1;
        for (; right - left > 1;)
        {
            int c = (right + left) / 2;
            if (nums[c] < nums.back())
                right = c;
            else
                left = c;
        }
        return nums[right];
    }
};

int main()
{
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7};
    rotate(nums.begin(), nums.begin() + 4, nums.end());
    for (int val : nums)
        cout << val << " ";

    Solution sol;
    cout << sol.findMin(nums);
}