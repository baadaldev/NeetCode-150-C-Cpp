/**
 * LeetCode 134: Gas Station
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        int total = 0, tank = 0, start = 0;
        for (size_t i = 0; i < gas.size(); ++i) {
            int diff = gas[i] - cost[i];
            total += diff;
            tank += diff;
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return total >= 0 ? start : -1;
    }
};
