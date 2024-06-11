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
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;

        vector<int> exchange(amount + 1, 1e6);
        exchange[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < coins.size(); ++j)
            {
                if (i - coins[j] == 0 || (i - coins[j] > 0 && exchange[i - coins[j]] != 1e6))
                {
                    exchange[i] = min(exchange[i - coins[j]] + 1, exchange[i]);
                }
            }
        }
        if (exchange[amount] == 1e6)
            return -1;
        return exchange[amount];
    }
};

int main()
{
    vector<int> coins{1, 2, 5};
    Solution sol;
    cout << sol.coinChange(coins, 8);
    return 0;
}