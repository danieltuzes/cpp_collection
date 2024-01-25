#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> excess;
        unordered_map<char, int> mandat;
        for (int k=0; k<t.size(); ++k)
            mandat[t[k]]++;
        
        int i=0;
        int j=0;
        for (;;)
        {
            if (mandat.count(s[j]))
            {
                mandat[s[j]]--;
                if (mandat[s[j]] == 0)
                    mandat.erase(s[j]);
                ++j;
                if (!mandat.size())
                    break;
            }
            else
            {
                excess[s[j]] += 1;
                ++j;
            }
            if (j == s.size())
                return "";
        }
        
        int minwidth = j-i;
        int minpos = 0;

        for (;;)
        {
            if (excess[s[i]])
            {
                excess[s[i]]--;
                ++i;
                if (j-i < minwidth)
                {
                    minwidth = j-i;
                    minpos = i;
                }
            }
            else
            {
                if (j == s.size())
                    return s.substr(minpos, minwidth);
                excess[s[j]]++;
                j++;
            }
        }
    }
};


int main()
{
    Solution s;
    cout << s.minWindow("ab", "a");
    cout << "hi";
}