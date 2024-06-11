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
#include <cmath>

using namespace std;

using pq = priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>;

class Solution
{
public:
    void push_if(pq &minHeap, int ai, vector<int> &a, int bi, vector<int> &b, set<pair<int, int>> &visited)
    {
        if (visited.find(pair<int, int>{ai, bi}) == visited.end())
        {
            minHeap.push(pair<int, pair<int, int>>{a[ai] + b[bi], pair<int, int>{ai, bi}});
            visited.insert(pair<int, int>{ai, bi});
        }
    }

    vector<vector<int>> kSmallestPairs(vector<int> a, vector<int> b, int k)
    {
        vector<vector<int>> ret;
        pq minHeap;
        set<pair<int, int>> visited;
        minHeap.push(pair<int, pair<int, int>>{a[0] + b[0], {0, 0}});
        for (int i = 0; i < k; ++i)
        {
            auto curr = minHeap.top();
            int ai = curr.second.first;
            int bi = curr.second.second;
            minHeap.pop();
            ret.push_back(vector<int>{a[ai], b[bi]});
            if (bi + 1 < b.size())
                push_if(minHeap, ai, a, bi + 1, b, visited);
            if (ai + 1 < a.size())
                push_if(minHeap, ai + 1, a, bi, b, visited);
        }
        return ret;
    }
};

int main()
{
    vector<int> a = {1, 2, 4, 5, 6};
    vector<int> b = {3, 5, 7, 9};
    Solution sol;
    cout << sol.kSmallestPairs(a, b, 20)[0][0];
    return 0;
}