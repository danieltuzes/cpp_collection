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
    vector<vector<int>> maxvals;
    vector<int> nums;
public:
    int rob(vector<int>& nums) {
        for (int i=0; i<nums.size(); ++i)
        {
            maxvals.push_back(vector<int>(nums.size(), 0));
        }
        this->nums = nums;
        return maxval(0,nums.size()-1);
    }
    
    int maxval(int start, int end)
    {
        if (start > end)
            return 0;
        if (maxvals[start][end])
            return maxvals[start][end];
        if (start == end)
            return nums[start];
        int partmax = 0;
        for (int i=start; i<= end; ++i)
        {
            partmax = max(partmax, maxval(start,i-2) + nums[i] + maxval(i+2, end));
        }
        maxvals[start][end] = partmax;
        return partmax;
    }
};

int main()
{
    Solution sol;
    vector<int> vals{1,2};
    cout << sol.rob(vals);
    
    return 0;
}
