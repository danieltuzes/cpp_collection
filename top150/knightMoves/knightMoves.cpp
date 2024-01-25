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

using cell = pair<int,int>;

class chessHash
{
public:
    size_t operator()(const cell& mycell) const
    {
        hash<int> hasher;
        size_t hash1 = hasher(mycell.first);
        size_t hash2 = hasher(mycell.second);
        return hash1 ^ (hash2 << 1);
    }
};

class Solution {
public:
    int minKnightMoves(int N, int startRow, int startCol, int targetRow, int targetCol) {
        unordered_set<cell, chessHash> visited;
        deque<cell> queue;
        cell target({targetCol, targetRow});
        cell start({startCol, startRow});

        if (target == start)
            return 0;

        visited.insert(start);
        queue.push_back(start);

        int step = 1;
        for (;; step++)
        {
            int n = queue.size();
            for (int i=0; i<n; ++i)
            {
                cell piv = queue.front();
                queue.pop_front();

                vector<cell> dirs = {{1,2}, {1,-2}, {2, 1}, {2,-1}, {-1,2}, {-1, -2}, {-2, 1}, {-2,-1}};
                int x0 = piv.first;
                int y0 = piv.second;

                for (auto dir:dirs)
                {
                    int x = x0+dir.first;
                    int y = y0+dir.second;
                    cell nominee({x,y});
                    if (x>=0 && x<N && y >= 0 && y<N && visited.find(nominee) == visited.end())
                    {
                        if (nominee == target)
                            return step;
                        visited.insert(nominee);
                        queue.push_back(nominee);
                    }
                }
            }
        }
        return step;
    }
};



int main()
{
    Solution sol;
    cout << sol.minKnightMoves(8,0,0,1,2);
    cout << sol.minKnightMoves(8,0,0,2,1);
    
    return 0;
}
