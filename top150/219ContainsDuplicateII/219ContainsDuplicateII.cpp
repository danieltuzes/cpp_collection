#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> occurred;
        for (int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            if (occurred.find(num) == occurred.end())
                occurred[num] = i;
            else
            {
                if (i - occurred[num] <= k)
                    return true;
                occurred[num] = i;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}