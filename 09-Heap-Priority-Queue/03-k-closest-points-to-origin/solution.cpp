/**
 * LeetCode 973: K Closest Points to Origin
 * Time Complexity: O(n log k)
 * Space Complexity: O(k)
 */
#include <vector>
#include <queue>

class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        auto dist = [](const std::vector<int>& p) { return p[0]*p[0] + p[1]*p[1]; };
        auto comp = [&](const std::vector<int>& a, const std::vector<int>& b) {
            return dist(a) < dist(b);
        };
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, decltype(comp)> maxHeap(comp);
        for (const auto& p : points) {
            maxHeap.push(p);
            if ((int)maxHeap.size() > k) maxHeap.pop();
        }
        std::vector<std::vector<int>> res;
        while (!maxHeap.empty()) {
            res.push_back(maxHeap.top());
            maxHeap.pop();
        }
        return res;
    }
};
