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
    bool isInterleave(string s1, string s2, string s3)
    {
        vector<pair<int, int>> alts;
        for (int i1 = 0, i2 = 0, i3 = 0; i3 < s3.size(); ++i3)
        {
            char c = s3[i3];
            if (i1 < s1.size() && s1[i1] == c && i2 < s2.size() && s2[i2] == c)
            {
                i1++;
                alts.push_back(make_pair<>(i1, i2 + 1));
            }
            else if (i1 < s1.size() && s1[i1] == c && (i2 == s2.size() || s2[i2] != c))
            {
                ++i1;
            }
            else if ((i1 == s1.size() || s1[i1] != c) && s2[i2] == c)
            {
                ++i2;
            }
            else // (s1[i1] != c && s2[i2] != c)
            {
                if (!alts.empty())
                {
                    i1 = alts.back().first;
                    i2 = alts.back().second;
                    i3 = i1 + i2 - 1;
                    alts.pop_back();
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.isInterleave("aabcc", "dbbca", "aadbbcbcac");
    return 0;
}