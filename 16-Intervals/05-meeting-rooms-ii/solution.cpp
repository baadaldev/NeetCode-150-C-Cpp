/**
 * LeetCode 253 / LintCode 919: Meeting Rooms II
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        std::vector<int> start, end;
        for (const auto& i : intervals) {
            start.push_back(i[0]);
            end.push_back(i[1]);
        }
        std::sort(start.begin(), start.end());
        std::sort(end.begin(), end.end());

        int s = 0, e = 0, count = 0, maxRooms = 0;
        while (s < (int)start.size()) {
            if (start[s] < end[e]) {
                count++; s++;
                maxRooms = std::max(maxRooms, count);
            } else {
                count--; e++;
            }
        }
        return maxRooms;
    }
};
