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
    bool validAnagram(string s, string t)
    {
        char letters[32] = {0};
        for (auto letter : s)
        {
            letters[letter - 'a']++;
        }
        for (auto letter : t)
        {
            letters[letter - 'a']--;
        }
        for (auto count : letters)
            if (count != 0)
                return false;
        return true;
    }
};

int main()
{
    Solution sol;
    cout << sol.validAnagram("hey", "heyy");
    return 0;
}
