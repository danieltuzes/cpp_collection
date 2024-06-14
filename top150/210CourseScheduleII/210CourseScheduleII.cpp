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

class Solution2
{
    bool canAbs(int course, vector<vector<int>> &prereqPerCourse, vector<int> &toComplete, vector<bool> &completed)
    {
        if (prereqPerCourse[course].empty())
        {
            if (!completed[course])
            {
                toComplete.push_back(course);
                completed[course] = true;
            }
        }
        else if (completed[course]) // loop in requirement
        {
            return false;
        }
        else
        {
            completed[course] = true;
            for (int prereq : prereqPerCourse[course])
            {
                if (!canAbs(prereq, prereqPerCourse, toComplete, completed))
                    return false;
            }
            prereqPerCourse[course] = vector<int>();
            toComplete.push_back(course);
        }
        return true;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> prereqPerCourse(numCourses, vector<int>());
        vector<bool> completed(numCourses, false);
        for (auto prerequisite : prerequisites)
        {
            prereqPerCourse[prerequisite[0]].push_back(prerequisite[1]);
        }

        vector<int> toComplete; // courses to complete in order from the beginning
        for (int i = 0; i < numCourses; ++i)
        {
            bool canMeet = canAbs(i, prereqPerCourse, toComplete, completed);
            if (!canMeet)
                return vector<int>();
        }
        return toComplete;
    }
};

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> buildsOn(numCourses);
        vector<int> NofDepies(numCourses, 0);
        for (auto prerequisite : prerequisites)
        {
            buildsOn[prerequisite[1]].push_back(prerequisite[0]);
            NofDepies[prerequisite[0]]++;
        }

        queue<int> canComplete;
        for (int i = 0; i < numCourses; ++i)
        {
            if (NofDepies[i] == 0)
            {
                canComplete.push(i);
            }
        }
        vector<int> complOrder;
        for (; canComplete.size();)
        {
            int curr = canComplete.front();
            canComplete.pop();
            complOrder.push_back(curr);

            for (int above : buildsOn[curr])
            {
                NofDepies[above]--;
                if (NofDepies[above] == 0)
                {
                    canComplete.push(above);
                }
            }
        }
        if (complOrder.size() == numCourses)
            return complOrder;
        return vector<int>();
    }
};

int main()
{
    vector<vector<int>> prerequisites{{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<vector<int>> prerequisites2{{0, 2}, {0, 3}, {0, 5}, {2, 3}, {2, 6}};
    vector<vector<int>> prerequisites3{{0, 2}, {0, 3}, {0, 5}, {2, 3}, {2, 6}, {6, 2}};
    Solution sol;
    auto res = sol.findOrder(7, prerequisites3);
    for (auto val : res)
    {
        cout << val;
    }
    return 0;
}