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


class Solution {
    unordered_set<string> words;

public:
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto& word : wordDict)
        {
            words.insert(word);
        }
        return canBeConstructed(s, 0);
    }

    bool canBeConstructed(string& s, int start)
    {
        if (start >= s.size())
            return true;
        for (int i=1; i<=s.size()-start; ++i)
        {
            if (words.find(s.substr(start,i)) != words.end())
            {
                if (canBeConstructed(s, start+i))
                    return true;
            }
        }
        return false;
    }
};


int main()
{
    Solution sol;
    vector<string> words = {"leet", "code"};
    cout << sol.wordBreak("leetcode",words);
    
    return 0;
}
