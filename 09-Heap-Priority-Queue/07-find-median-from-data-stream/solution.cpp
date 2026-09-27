/**
 * LeetCode 295: Find Median from Data Stream
 * Time Complexity: addNum O(log n), findMedian O(1)
 * Space Complexity: O(n)
 */
#include <queue>
#include <vector>

class MedianFinder {
    std::priority_queue<int> maxHeap; // stores smaller half
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // stores larger half
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};
