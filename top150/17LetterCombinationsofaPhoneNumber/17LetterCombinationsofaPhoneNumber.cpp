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
    vector<char> digtochar(char digit)
    {
        if (digit == '2')
            return vector<char>{'a', 'b', 'c'};
        if (digit == '3')
            return vector<char>{'d', 'e', 'f'};
        if (digit == '4')
            return vector<char>{'h', 'i', 'j'};
        if (digit == '5')
            return vector<char>{'k', 'l', 'm'};
        if (digit == '6')
            return vector<char>{'n', 'o', 'p'};
        if (digit == '7')
            return vector<char>{'p', 'q', 'r', 's'};
        if (digit == '8')
            return vector<char>{'t', 'u', 'v'};

        return vector<char>{'w', 'x', 'y', 'z'};
    }

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ret({""});
        for (char digit : digits)
        {
            auto nextletters = digtochar(digit);
            int n = ret.size();
            for (int i = 0; i < n; ++i)
            {
                for (int j = 1; j < nextletters.size(); ++j)
                {
                    ret.push_back(ret[i] + nextletters[j]);
                }
                ret[i] += nextletters[0];
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    for (auto word : sol.letterCombinations("23"))
    {
        cout << word;
    }
}