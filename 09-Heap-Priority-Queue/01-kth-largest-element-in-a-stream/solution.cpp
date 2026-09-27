/**
 * LeetCode 703: Kth Largest Element in a Stream
 * Time Complexity: O(log k) per add
 * Space Complexity: O(k)
 */
#include <queue>
#include <vector>

class KthLargest {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    int kSize;
public:
    KthLargest(int k, std::vector<int>& nums) : kSize(k) {
        for (int n : nums) add(n);
    }
    
    int add(int val) {
        minHeap.push(val);
        if ((int)minHeap.size() > kSize) minHeap.pop();
        return minHeap.top();
    }
};
