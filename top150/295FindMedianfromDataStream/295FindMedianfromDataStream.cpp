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

class MedianFinder
{
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> upper;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (lower.empty() || num <= lower.top())
            lower.push(num);
        else
            upper.push(num);

        int diff = lower.size() - upper.size();
        if (diff == -1)
        {
            lower.push(upper.top());
            upper.pop();
        }
        else if (diff == 2)
        {
            upper.push(lower.top());
            lower.pop();
        }
    }

    double findMedian()
    {
        int diff = lower.size() - upper.size();
        if (diff == 0)
            return (lower.top() + upper.top()) / 2.;
        return lower.top();
    }
};

int main()
{
    MedianFinder sol;
    sol.addNum(10);
    sol.addNum(1);
    sol.addNum(3);
}