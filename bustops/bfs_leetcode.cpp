#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if (source == target)
            return 0;
        int count = 1;
        unordered_map<int, vector<int>> stops;
        for (int route = 0; route < routes.size(); ++route)
        {
            for (int stop : routes[route])
                stops[stop].push_back(route);
        }

        deque<int> queue;
        unordered_set<int> used_route;

        for (int route : stops[source])
        {
            queue.push_back(route);
            used_route.insert(route);
        }

        for (; queue.size();)
        {
            int size = queue.size();
            for (int i = 0; i < size; ++i)
            {
                int route = queue.front();
                queue.pop_front();
                for (int stop: routes[route])
                {
                    if (stop == target)
                        return count;
                    for (int new_route: stops[stop])
                    {
                        if (!used_route.count(new_route))
                        {
                            queue.push_back(new_route);
                            used_route.insert(new_route);
                        }
                            
                    }
                }
            }
            count++;
        }
        return -1;
    }
};

int main()
{
    auto routes = vector<vector<int>>({{25,33},{3,5,13,22,23,29,37,45,49},{15,16,41,47},{5,11,17,23,33},{10,11,12,29,30,39,45},{2,5,23,24,33},{1,2,9,19,20,21,23,32,34,44},{7,18,23,24},{1,2,7,27,36,44},{7,14,33}});
    Solution sol;
    cout << sol.numBusesToDestination(routes,2,8);
    return 0;
}