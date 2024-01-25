#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>
#include <string>

using namespace std;


class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        int i=0;
        for (; i<s.size() && j<t.size(); ++j)
        {
            if (t[j] == s[i])
                ++i;
        }
        if (i==s.size())
            return true;
        return false;
    }
};

int main()
{
    Solution sol;
    cout << sol.isSubsequence("axc", "ahbgdc");
    
    return 0;
}

    