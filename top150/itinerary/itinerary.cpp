#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <functional>

using namespace std;

class Solution {
private:
    unordered_map<string, multiset<string>> graph;
    vector<string> itinerary;

    void dfs(const string& airport) {
        while (!graph[airport].empty()) {
            string next_airport = *graph[airport].begin();
            graph[airport].erase(graph[airport].begin());
            dfs(next_airport);
        }
        itinerary.push_back(airport);
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Construct the graph
        for (const auto& ticket : tickets) {
            graph[ticket[0]].insert(ticket[1]);
        }

        // Start DFS from "JFK"
        dfs("JFK");

        // Reverse the itinerary to get the correct order
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }   
};

void printItinerary(const vector<string>& itinerary) {
    for (const string& stop : itinerary) {
        cout << stop << (stop == itinerary.back() ? "\n" : " -> ");
    }
}

int main() {
    Solution solution;

    // Test Case for the itinerary JFK -> A -> D -> A -> B
    vector<vector<string>> tickets = {
        {"JFK", "A"}, {"A", "D"}, {"D", "A"}, {"A", "B"}
    };

    vector<string> itinerary = solution.findItinerary(tickets);
    cout << "Calculated Itinerary: ";
    printItinerary(itinerary);

    return 0;
}
