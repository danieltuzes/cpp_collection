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
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(),1);
        for (int i=1; i<ratings.size(); ++i)
        {
            if (ratings[i] > ratings[i-1])
                candies[i] = candies[i-1]+1;
        }
        int ret = candies.back();
        for (int j=ratings.size()-2; j >= 0; --j)
        {
            if (ratings[j] > ratings[j+1])
                candies[j] = max(candies[j+1]+1,candies[j]);
            ret += candies[j];
        }
        return ret;
    }
};

int main()
{
    vector<int> nums({1,2,3,8,6,2,2,3});
    Solution sol;
    cout << sol.candy(nums);
    return 0;
}

    