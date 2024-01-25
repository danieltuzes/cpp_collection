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
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        n++;
        deque<int> reachtimes(n, -1);
        reachtimes[k] = 0;


        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> dirs;  // pair<time, target>
        dirs.push({0, k});

        vector<vector<pair<int,int>>> neighbors(n, vector<pair<int,int>>()); // neig: pair<target, time>
        for (auto time: times)
        {
            neighbors[time[0]].emplace_back(make_pair(time[1], time[2]));
        }

        for (;!dirs.empty();)
        {
            auto piv = dirs.top();  // piv: pair<time, target>
            dirs.pop();

            int pivreach = piv.first;
            int pivnode = piv.second;

            for (auto neig: neighbors[pivnode])
            {
                int nom_node = neig.first;
                int nom_reacht = neig.second + pivreach;
                int curr_time = reachtimes[nom_node];
                if (curr_time < 0 || curr_time > nom_reacht)
                {
                    reachtimes[nom_node] = nom_reacht;
                    dirs.push({nom_reacht, nom_node});
                }
            }
        }
        reachtimes.pop_front();
        auto mintime = min_element(reachtimes.begin(), reachtimes.end());
        auto maxtime = max_element(reachtimes.begin(), reachtimes.end());
        if (*mintime == -1)
            return -1;
        return *maxtime;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n1 = 4, k1 = 2;
    cout << "Test Case 1: " << solution.networkDelayTime(times1, n1, k1) << endl;
}