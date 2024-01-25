#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int laststart = 0;
        int laststartheight = 0;
        int ret = 0;
        for (int i=0; i<height.size()-1; ++i)
        {
            if (height[i+1] < height[i])
            {
                laststart = i;
                laststartheight = height[i];
                int pond = 0;
                for (; i < height.size()-1; ++i)
                {
                    if (height[i+1] >= laststartheight)
                    {
                        ret += pond;
                        pond = 0;
                        break;
                        laststart = i;
                    }
                    pond += laststartheight - height[i+1];
                }
            }   
        }

        for (int j=height.size()-1; j>=laststart+1; --j)
        {
            if (height[j-1] < height[j])
            {
                laststartheight = height[j];
                int pond = 0;
                for (; j >= laststart+1; --j)
                {
                    if (height[j-1] >= laststartheight)
                    {
                        ret += pond;
                        pond = 0;
                        break;
                    }
                    pond += laststartheight - height[j-1];
                }
            }   
        }
    return ret;
    }
};

int main()
{
    vector<int> nums({1,0,2,1,0,5,2,3,0,1,0,4,2});
    Solution sol;
    cout << sol.trap(nums);
    return 0;
}