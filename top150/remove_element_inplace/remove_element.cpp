#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int to_fill = 0;
        for (int pivot = 0; pivot < nums.size();++pivot)
        {
            if (nums[pivot] != val)
            {
                nums[to_fill] = nums[pivot];
                ++to_fill;
            }
        }
        return to_fill;
    }
};

int main()
{
    vector<int> nums({0,1,2,2,3,0,4,2});
    Solution sol;
    cout << sol.removeElement(nums,2) << endl <<endl;
    for (int val: nums) cout << val << endl;
    return 0;
}