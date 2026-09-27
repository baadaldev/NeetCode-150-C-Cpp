/**
 * LeetCode 1046: Last Stone Weight
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <queue>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        std::priority_queue<int> maxHeap(stones.begin(), stones.end());
        while (maxHeap.size() > 1) {
            int y = maxHeap.top(); maxHeap.pop();
            int x = maxHeap.top(); maxHeap.pop();
            if (y != x) maxHeap.push(y - x);
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
