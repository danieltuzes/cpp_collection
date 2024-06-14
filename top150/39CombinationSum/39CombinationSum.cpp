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
    void findRest(vector<vector<int>> &ret, vector<int> &curr, vector<int> &candidates, int start, int remaining)
    {
        if (!remaining)
        {
            ret.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); ++i)
        {
            if (candidates[i] > remaining)
            {
                return;
            }

            curr.push_back(candidates[i]);
            findRest(ret, curr, candidates, i, remaining - candidates[i]);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ret;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        findRest(ret, curr, candidates, 0, target);
        return ret;
    }
};

class Solution2
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<vector<int>>> builds(target + 1, vector<vector<int>>(0)); // from [0,7]
        builds[0].push_back(vector<int>(0));
        for (int i = 1; i <= target; ++i)
        {
            for (int candidate : candidates)
            {
                int cand_i = i - candidate;
                if (cand_i >= 0 && cand_i <= target && !builds[cand_i].empty())
                {
                    for (auto build_ex : builds[cand_i])
                    {
                        if (build_ex.empty() || candidate >= build_ex.back())
                        {
                            build_ex.push_back(candidate);
                            builds[i].push_back(build_ex);
                        }
                    }
                }
            }
        }
        if (builds.back().empty())
            builds.back().push_back(vector<int>(0));

        return builds.back();
    }
};

int main()
{
    Solution solution;
    vector<int> candidates{2, 3, 6, 7};
    solution.combinationSum(candidates, 7);

    return 0;
}