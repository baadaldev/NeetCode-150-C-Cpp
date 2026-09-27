/**
 * LeetCode 1851: Minimum Interval to Include Each Query
 * Time Complexity: O(n log n + q log q)
 * Space Complexity: O(n + q)
 */
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    std::vector<int> minInterval(std::vector<std::vector<int>>& intervals, std::vector<int>& queries) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::pair<int, int>> sortedQ;
        for (int i = 0; i < (int)queries.size(); ++i) sortedQ.push_back({queries[i], i});
        std::sort(sortedQ.begin(), sortedQ.end());

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
        std::vector<int> res(queries.size());
        int i = 0, n = intervals.size();

        for (auto [q, idx] : sortedQ) {
            while (i < n && intervals[i][0] <= q) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top().second < q) pq.pop();
            res[idx] = pq.empty() ? -1 : pq.top().first;
        }
        return res;
    }
};
