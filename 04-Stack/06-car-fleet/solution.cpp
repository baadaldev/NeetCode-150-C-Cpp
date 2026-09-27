/**
 * LeetCode 853: Car Fleet
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int carFleet(int target, std::vector<int>& position, std::vector<int>& speed) {
        int n = position.size();
        std::vector<std::pair<int, double>> cars(n);
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
        }
        std::sort(cars.rbegin(), cars.rend());

        int fleets = 0;
        double maxTime = 0.0;
        for (const auto& [pos, time] : cars) {
            if (time > maxTime) {
                maxTime = time;
                fleets++;
            }
        }
        return fleets;
    }
};
