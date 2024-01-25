#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int to_fill = 1;
        for (int pivot = 1; pivot < nums.size(); ++pivot)
        {
            if (nums[pivot-1] != nums[pivot])
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
    vector<int> nums({0,1,2,2,3,6,6,6});
    Solution sol;
    cout << sol.removeDuplicates(nums) << endl <<endl;
    for (int val: nums) cout << val << endl;
    return 0;
}

    