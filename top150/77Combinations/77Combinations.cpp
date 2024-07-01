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
    void itUp(int n, int k, vector<vector<int>> &combos, vector<int> &combo)
    {
        if (k == 0)
        {
            combos.push_back(combo);
            return;
        }

        for (int i = k; ((k == combo.size() && i <= n) || (k < combo.size() && i < combo[k])); ++i)
        {
            combo[k - 1] = i;
            itUp(n, k - 1, combos, combo);
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> combos;
        vector<int> combo;
        for (int i = 1; i <= k; ++i)
            combo.push_back(i);
        itUp(n, k, combos, combo);

        return combos;
    }
};

int main()
{
    Solution sol;
    for (auto combo : sol.combine(3, 1))
    {
        for (auto val : combo)
            cout << val;
        cout << endl;
    }
    return 0;
}