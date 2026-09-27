/**
 * LeetCode 252 / LintCode 920: Meeting Rooms
 * Time Complexity: O(n log n)
 * Space Complexity: O(1)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() <= 1) return true;
        std::sort(intervals.begin(), intervals.end());
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i - 1][1]) return false;
        }
        return true;
    }
};
