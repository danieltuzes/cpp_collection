#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort the intervals based on the first value
        sort(intervals.begin(), intervals.end(), [](auto& lhs, auto& rhs){return lhs[0] < rhs[0];});

        vector<vector<int>> ret;
        ret.emplace_back(intervals[0]);
        // for every interval from 1, check if the first value lies between the previous range,
        // and if does, merge the last and the current one
        for (int i=1; i<intervals.size(); ++i)
        {
            if (intervals[i][0] <= ret.back()[1])
            {
                ret.back() = vector<int>{ret.back()[0], intervals[i][1]};
            }
            else
            {
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> intervals{{1,3},{2,6},{8,10},{15,18}};
    cout << sol.merge(intervals)[0][2];
    
    return 0;
}

