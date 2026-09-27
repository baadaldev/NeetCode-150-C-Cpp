/**
 * LeetCode 746: Min Cost Climbing Stairs
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        for (int i = (int)cost.size() - 3; i >= 0; --i) {
            cost[i] += std::min(cost[i + 1], cost[i + 2]);
        }
        return std::min(cost[0], cost[1]);
    }
};
