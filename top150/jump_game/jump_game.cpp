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
    bool canJump(vector<int>& nums) {
        int moves = 0;
        int i=0;
        for (;;)
        {
            
            if (i==nums.size()-1)
            {
                return true;
            }
            else
            {
                moves = max(moves, nums[i]);
                if (moves)
                {
                    ++i;
                    --moves;
                }
                else
                    return false;    
            }
        }
    }
};

int main()
{
    vector<int> nums({1});
    Solution sol;
    cout << sol.canJump(nums);
    return 0;
}

    

