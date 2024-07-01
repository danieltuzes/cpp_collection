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
    void addNewP(int n, int opened, int opens, vector<string> &combos, string &combo)
    {
        if (opens == n && opened == 0)
        {
            combos.push_back(combo);
            return;
        }

        if (opens < n)
        {
            combo.push_back('(');
            addNewP(n, opened + 1, opens + 1, combos, combo);
            combo.pop_back();
        }
        if (opened > 0)
        {
            combo.push_back(')');
            addNewP(n, opened - 1, opens, combos, combo);
            combo.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> combos;
        string combo = "";
        addNewP(n, 0, 0, combos, combo);
        return combos;
    }
};

int main()
{
    Solution sol;
    for (auto combo : sol.generateParenthesis(1))
        cout << combo << endl;
}