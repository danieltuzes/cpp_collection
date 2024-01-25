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
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> occ;
        for (char letter: magazine)
            occ[letter] += 1;
        
        for (char letter : ransomNote)
        {
            if (occ[letter])
                occ[letter] -= 1;
            else
                return false;
        }
        return true;
    }
};


int main()
{
    Solution s;
    vector<vector<int>> matrix = {{1,1},{1,0}};
    s.canConstruct("aa", "ab");
    cout << matrix[0][1];
}