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
    bool neighbor(string beginWord, string endWord)
    {
        bool hasDiff = false;
        for (int i = 0; i < beginWord.size(); i++)
        {
            if (beginWord[i] != endWord[i])
            {
                if (hasDiff)
                    return false;
                hasDiff = true;
            }
        }
        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        if (beginWord == endWord)
            return 0;
        queue<string> q;
        int steps = 1;
        q.push(beginWord);
        for (int rsize = q.size(); rsize > 0; rsize = q.size())
        {
            for (int j = 0; j < rsize; ++j)
            {
                auto curr_s = q.front();
                if (neighbor(curr_s, endWord))
                    return steps;

                q.pop();
                for (int i = 0; i < wordList.size(); ++i)
                {
                    if (neighbor(curr_s, wordList[i]))
                    {
                        q.push(wordList[i]);
                        if (i != wordList.size() - 1)
                            swap(wordList[i], wordList.back());
                        wordList.pop_back();
                        i--;
                    }
                }
            }
            steps++;
        }
        return 0;
    }
};

int main()
{
    string beginword = "hit";
    string endword = "ges";
    vector<string> wordList = {"sap", "het", "hut", "get", "hes",
                               "oul"};
    Solution sol;
    cout << sol.ladderLength(beginword, endword, wordList);
}