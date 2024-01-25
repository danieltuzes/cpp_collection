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
    int minDistance(string word1, string word2) {
        vector<vector<int>> n(word1.size()+1, vector<int>(word2.size()+1, 0));
        for (int i=0; i<word1.size()+1; ++i)
            n[i][0] = i;

        for (int j=0; j<word2.size()+1; ++j)
            n[0][j] = j;
        
        for (int i=0; i<word1.size(); ++i)
        {
            int I=i+1;
            for (int j=0; j<word2.size(); ++j)
            {
                int J=j+1;
                n[I][J] = min(n[I][J-1], n[I-1][J])+1;
                if (word1[i] == word2[j])
                    n[I][J] = min(n[I][J], n[I-1][J-1]);
                else
                    n[I][J] = min(n[I][J], n[I-1][J-1]+1);
            }

        }
        return n.back().back();
    }
};

int main()
{
    Solution sol;
    cout << sol.minDistance("ros","horse");
    
    return 0;
}
