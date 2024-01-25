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
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (k==0 || s.empty())
        return 0;
    char lookup[26] = {0};
    lookup[s[0] - 'a'] = 1;
    int unique = 1;
    int maxlength = 1;
    for (int i=0, j=1; j<s.size();)
    {
        if (lookup[s[j]-'a'] > 0) // already in
        {
            lookup[s[j]-'a']++;
            j++;
            maxlength = max(maxlength, j-i);
        }
        else if (unique == k) // not in and full
        {
            lookup[s[i]-'a']--;
            if (lookup[s[i]-'a'] == 0)
                --unique;
            ++i;
        }
        else // not in and not full
        {
            lookup[s[j]-'a']++;
            unique++;
            ++j;
            maxlength = max(maxlength, j-i);
        }
    }
    return maxlength;
    }
};


class Solution2 {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
    if (k==0 || s.empty())
        return 0;
    
    unordered_map<char,int> occ;
    occ[s[0]] = 1;
    int maxlength = 1;
    for (int i=0, j=1; j<s.size();)
    {
        if (occ.find(s[j]) != occ.end()) // in
        {
            occ[s[j]] +=1;
            ++j;
            maxlength = max(maxlength,j-i);
        }
        else if (occ.size() == k)  // not in and full
        {
            occ[s[i]] -= 1;
            if (occ[s[i]] == 0)
                occ.erase(s[i]);
            i++;
        }
        else  // not in and not full
        {
            occ[s[j]] = 1;
            ++j;
            maxlength = max(maxlength,j-i);
        }
    }
    return maxlength;
    }
};

int main()
{
    Solution solution;
    
    // Test Case 1
    cout << "Test Case 1: " << solution.lengthOfLongestSubstringKDistinct("eceba", 2) << " (Expected: 3)" << endl;

    // Test Case 2
    cout << "Test Case 2: " << solution.lengthOfLongestSubstringKDistinct("aa", 1) << " (Expected: 2)" << endl;

    // Test Case 3
    cout << "Test Case 3: " << solution.lengthOfLongestSubstringKDistinct("aabbcc", 1) << " (Expected: 2)" << endl;

    // Test Case 4
    cout << "Test Case 4: " << solution.lengthOfLongestSubstringKDistinct("abaccc", 2) << " (Expected: 4)" << endl;

    // Test Case 5
    cout << "Test Case 5: " << solution.lengthOfLongestSubstringKDistinct("", 3) << " (Expected: 0)" << endl;

    // Test Case 6
    cout << "Test Case 6: " << solution.lengthOfLongestSubstringKDistinct("abaccc", 0) << " (Expected: 0)" << endl;

    return 0;
}
