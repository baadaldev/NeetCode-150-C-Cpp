/**
 * LeetCode 56: Merge Intervals
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;
        std::sort(intervals.begin(), intervals.end());

        std::vector<std::vector<int>> res = {intervals[0]};
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= res.back()[1]) {
                res.back()[1] = std::max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
