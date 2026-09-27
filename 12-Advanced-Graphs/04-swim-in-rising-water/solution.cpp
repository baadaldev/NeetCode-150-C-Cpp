/**
 * LeetCode 778: Swim in Rising Water
 * Time Complexity: O(n^2 log n)
 * Space Complexity: O(n^2)
 */
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int swimInWater(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::priority_queue<std::tuple<int, int, int>, std::vector<std::tuple<int, int, int>>, std::greater<>> pq;
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));

        pq.push({grid[0][0], 0, 0});
        visited[0][0] = true;
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};

        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();
            if (r == n - 1 && c == n - 1) return t;

            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    pq.push({std::max(t, grid[nr][nc]), nr, nc});
                }
            }
        }
        return 0;
    }
};
