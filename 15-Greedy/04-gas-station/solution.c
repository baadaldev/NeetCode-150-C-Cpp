/**
 * LeetCode 134: Gas Station
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < gasSize; i++) {
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
