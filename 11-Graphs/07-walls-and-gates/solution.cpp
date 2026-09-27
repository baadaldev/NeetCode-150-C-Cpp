/**
 * LeetCode 286: Walls and Gates
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 */
#include <vector>
#include <queue>

class Solution {
public:
    void wallsAndGates(std::vector<std::vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        std::queue<std::pair<int, int>> q;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (rooms[r][c] == 0) q.push({r, c});
            }
        }
        int dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && rooms[nr][nc] == 2147483647) {
                    rooms[nr][nc] = rooms[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
