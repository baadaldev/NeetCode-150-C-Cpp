/**
 * LeetCode 746: Min Cost Climbing Stairs
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int minCostClimbingStairs(int* cost, int costSize) {
    for (int i = costSize - 3; i >= 0; i--) {
        cost[i] += MIN(cost[i + 1], cost[i + 2]);
    }
    return MIN(cost[0], cost[1]);
}
