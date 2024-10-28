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

class Solution
{
public:
    int factorialZeros(int n)
    {
        int num0s;
        for (int div = 5; div < 1e4; div *= 5)
        {
            num0s += n / div;
        }
        return n;
    }
};

int main()
{
    Solution sol;
    cout << sol.factorialZeros(3);
    cout << sol.factorialZeros(5);
    cout << sol.factorialZeros(10);
    cout << sol.factorialZeros(18);
    return 0;
}