/**
 * LeetCode 621: Task Scheduler
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::vector<int> freq(26, 0);
        for (char t : tasks) freq[t - 'A']++;
        int maxF = *std::max_element(freq.begin(), freq.end());
        int maxCount = std::count(freq.begin(), freq.end(), maxF);
        int ans = (maxF - 1) * (n + 1) + maxCount;
        return std::max(ans, (int)tasks.size());
    }
};
