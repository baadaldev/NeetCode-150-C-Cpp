/**
 * LeetCode 2013: Detect Squares
 * Time Complexity: add O(1), count O(N)
 * Space Complexity: O(N)
 */
#include <vector>
#include <unordered_map>
#include <cmath>

class DetectSquares {
    std::unordered_map<int, std::unordered_map<int, int>> pts;
public:
    DetectSquares() {}
    
    void add(std::vector<int> point) {
        pts[point[0]][point[1]]++;
    }
    
    int count(std::vector<int> point) {
        int px = point[0], py = point[1];
        int total = 0;
        for (const auto& [x, yMap] : pts) {
            if (x == px) continue;
            int side = std::abs(px - x);
            for (int y : {py + side, py - side}) {
                if (pts[x].count(y) && pts[px].count(y)) {
                    total += pts[x][py] * pts[px][y] * pts[x][y];
                }
            }
        }
        return total;
    }
};
