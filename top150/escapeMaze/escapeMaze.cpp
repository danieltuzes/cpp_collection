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

struct PairHash {
    size_t operator()(const vector<int>& vec) const {
        std::hash<int> hasher;
        size_t hash1 = hasher(vec[0]);
        size_t hash2 = hasher(vec[1]);

        // Combine the two hash values
        return hash1 ^ (hash2 << 1);
    }
};

class Solution {
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<vector<int>, PairHash> blocked_s;
        for (auto val: blocked)
        {
            blocked_s.insert(val);
        }
        return (escapeOrMeet(blocked_s, source, target) &&  escapeOrMeet(blocked_s, target, source));
    }



    bool escapeOrMeet(unordered_set<vector<int>, PairHash> blocked, vector<int>& source, vector<int>& target)
    {
        unordered_set<vector<int>, PairHash> seen;
        
        deque<vector<int>> queue;
        vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue.emplace_back(source);

        for (;;)
        {
            auto piv = queue.front();
            queue.pop_front();
            seen.insert(piv);

            if (piv == target)
                return true;
            
            for (auto dir: dirs)
            {
                int x = piv[0] + dir[0];
                int y = piv[1] + dir[1];
                vector<int> nominee({x,y});
                if (x >= 0 && x<1e6 && y >= 0 && y < 1e6 && seen.find(nominee) == seen.end() && blocked.find(nominee) == blocked.end())
                {
                    queue.push_back(nominee);
                }
            }

            if (seen.size() > 200*200/2)
                return true;
            if (queue.empty())
                return false;
        }
    }
};


int main()
{
    Solution sol;
    vector<vector<int>> blocked;
    vector<int> source({0,0});
    vector<int> target({999999,999999});
    cout << sol.isEscapePossible(blocked, source, target);
    return 0;
}