#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int mod = 0; mod < gcd(nums.size(),k); ++mod)
        {
            int tmp = nums[mod];
            for (int pivot=mod;;)
            {
                nums[pivot] = nums[(pivot-k+nums.size())%nums.size()];
                pivot = (pivot-k+nums.size())%nums.size();
                if (pivot==(mod+k)%nums.size())
                    break;
            }
            nums[mod+k] = tmp;
        }
    }
};

int main()
{
    vector<int> nums({1,2,3,4,5,6,7});
    Solution sol;
    sol.rotate(nums,3);
    for (int val: nums) cout << val << endl;
    return 0;
}

    

