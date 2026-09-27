/**
 * LeetCode 332: Reconstruct Itinerary
 * Time Complexity: O(E log E)
 * Space Complexity: O(V + E)
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

class Solution {
    std::unordered_map<std::string, std::priority_queue<std::string, std::vector<std::string>, std::greater<std::string>>> graph;
    std::vector<std::string> route;

    void dfs(const std::string& airport) {
        auto& dests = graph[airport];
        while (!dests.empty()) {
            std::string next = dests.top(); dests.pop();
            dfs(next);
        }
        route.push_back(airport);
    }
public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        for (const auto& t : tickets) graph[t[0]].push(t[1]);
        dfs("JFK");
        std::reverse(route.begin(), route.end());
        return route;
    }
};
