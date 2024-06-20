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
    string longestPalindrome(string s)
    {
        int longest = 0;
        int start_index = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; i + j < n && i - j >= 0; ++j)
            {
                if (s[i + j] != s[i - j])
                    break;
                else if (2 * j + 1 > longest)
                {
                    longest = 2 * j + 1;
                    start_index = i - j;
                }
            }
            for (int j = 0; i - j >= 0 && i + j + 1 < n; ++j)
            {
                if (s[i + j + 1] != s[i - j])
                    break;
                else if (2 * j + 2 > longest)
                {
                    longest = 2 * j + 2;
                    start_index = i - j;
                }
            }
        }
        return s.substr(start_index, longest);
    }
};

int main()
{
    string s = "babad";
    Solution sol;
    cout << sol.longestPalindrome(s);
}