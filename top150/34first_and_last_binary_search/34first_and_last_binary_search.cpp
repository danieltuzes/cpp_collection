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

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        vector<int> ret{-1,-1};
        for (;left <= right;)
        {
            int mid = (left+right)/2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        if (!(left < nums.size() && nums[left] == target))
            return ret;
        ret[0] = left;

        right = nums.size()-1;
        for (;left <= right;)
        {
            int mid = (left+right)/2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        ret[1] = right;
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{5,7,7,8,8,10};
    auto ret = sol.searchRange(nums, 8);
    cout << ret[0] << ret[1];
    
    return 0;
}
