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
    double getPath(unordered_map<string, vector<pair<string, double>>> &graph, string &num, string &den)
    {
        if (graph.find(num) == graph.end() || graph.find(den) == graph.end())
            return -1;
        if (num == den)
            return 1;

        vector<string> next_lentries;
        unordered_map<string, pair<string, double>> steps;
        next_lentries.push_back(num);
        steps[num] = make_pair<>("", 1);
        for (int i = 0;;)
        {
            int clec = next_lentries.size(); // cumulative level entry count
            if (i == clec)
                break;
            for (; i < clec; ++i)
            {
                string parent = next_lentries[i];
                for (int j = 0; j < graph[parent].size(); ++j)
                {
                    auto child = graph[parent][j];
                    if (steps.find(child.first) != steps.end())
                        continue;
                    steps[child.first] = make_pair<>(parent, child.second);
                    next_lentries.push_back(child.first);
                    if (next_lentries.back() == den)
                        break;
                }
                if (next_lentries.back() == den)
                    break;
            }
            if (next_lentries.back() == den)
                break;
        }
        if (next_lentries.back() != den)
            return -1;

        double prod = 1;
        for (string node = den; node != "";)
        {
            auto parent = steps[node];
            prod *= parent.second;
            node = parent.first;
        }
        return prod;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        // set up a graph of
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); ++i)
        {
            graph[equations[i][0]].push_back(make_pair<>(equations[i][1], values[i]));
            graph[equations[i][1]].push_back(make_pair<>(equations[i][0], 1 / values[i]));
        }
        vector<double> rets;
        for (auto query : queries)
        {
            string num = query[0];
            string den = query[1];
            rets.push_back(getPath(graph, num, den));
        }
        return rets;
    }
};

int main()
{
    vector<vector<string>> equations = {{"a", "b"}, {"b", "c"}};
    vector<double> values = {2, 3};
    vector<vector<string>> queries = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
    Solution sol;
    cout << sol.calcEquation(equations, values, queries)[0];
    return 0;
}