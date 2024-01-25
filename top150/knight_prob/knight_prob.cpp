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
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> probs(n, vector<double>(n,0));
        probs[row][column] = 1;
        for (int i=0; i<k; ++i)
            iterate(probs);
        
        double sumprob = 0;
        for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            sumprob += probs[i][j];

        return sumprob;
    }
    
    void iterate(vector<vector<double>>& probs)
    {
        int n = probs.size();
        vector<vector<double>> probs_new(n, vector<double>(n,0));
        for (int i = 0; i<n; ++i)
        for (int j = 0; j<n; ++j)
            probs_new[i][j] = getProb(probs, i, j);
        
        probs = probs_new;
    }

    double getProb(const vector<vector<double>>& probs, int i, int j)
    {
        double prob = 0;
        prob += atProbs(probs,i+2,j+1);
        prob += atProbs(probs,i+2,j-1);
        prob += atProbs(probs,i+1,j+2);
        prob += atProbs(probs,i+1,j-2);
        prob += atProbs(probs,i-1,j+2);
        prob += atProbs(probs,i-1,j-2);
        prob += atProbs(probs,i-2,j+1);
        prob += atProbs(probs,i-2,j-1);
        return prob/8;
    }

    double atProbs(const vector<vector<double>>& probs, int i, int j)
    {
        int n = probs.size();
        if (i<0 || j<0 || i>n-1 || j>n-1)
            return 0;
        else
            return probs[i][j];
    }
};

int main()
{
    Solution sol;
    cout << sol.knightProbability(3,2,0,0);
    return 0;
}