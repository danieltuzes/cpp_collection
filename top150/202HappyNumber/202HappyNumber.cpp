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

class Solution
{
    int getSqSum(int x)
    {
        int sqSum = 0;
        for (; x > 0;)
        {
            int xmod = x % 10;
            sqSum += xmod * xmod;
            x /= 10;
        }
        return sqSum;
    }

public:
    bool isHappy(int n)
    {
        for (unordered_set<int> prevSumSq; n != 1; n = getSqSum(n))
        {
            if (prevSumSq.find(n) != prevSumSq.end())
                return false;
            prevSumSq.insert(n);
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isHappy(3);
    return 0;
}