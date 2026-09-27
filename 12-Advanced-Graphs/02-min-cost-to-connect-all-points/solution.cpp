/**
 * LeetCode 1584: Min Cost to Connect All Points
 * Time Complexity: O(V^2)
 * Space Complexity: O(V)
 */
#include <vector>
#include <cmath>
#include <climits>

class Solution {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        int n = points.size();
        std::vector<int> dist(n, INT_MAX);
        std::vector<bool> visited(n, false);
        dist[0] = 0;
        int totalCost = 0;

        for (int i = 0; i < n; ++i) {
            int u = -1;
            for (int j = 0; j < n; ++j) {
                if (!visited[j] && (u == -1 || dist[j] < dist[u])) u = j;
            }
            visited[u] = true;
            totalCost += dist[u];
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int d = std::abs(points[u][0] - points[v][0]) + std::abs(points[u][1] - points[v][1]);
                    dist[v] = std::min(dist[v], d);
                }
            }
        }
        return totalCost;
    }
};
