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
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        
        if (nums.back() < nums.front())
        {
            for (;left != right;)
            {
                int mid = (left+right)/2;
                if (nums[mid] >= nums[0])
                    left = mid+1;
                else
                    right = mid;
            }
            if (target < nums.front())
                right = nums.size()-1;
            else
            {
                right--;
                left = 0;
            }
        }
        
        for (;left<=right;)
        {
            int mid = (left+right)/2;
            if (nums[mid] <= target)
                left = mid+1;
            else
                right = mid-1;
        }
        if (nums[left-1] == target)
            return left-1;
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{3,1};
    // vector<int> nums{1};
    cout << sol.search(nums, 1);
    
    return 0;
}
