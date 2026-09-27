/**
 * LeetCode 295: Find Median from Data Stream
 * Time Complexity: addNum: O(log n), findMedian: O(1)
 * Space Complexity: O(n)
 */
#include <stdlib.h>

typedef struct {
    int dummy;
} MedianFinder;

MedianFinder* medianFinderCreate() {
    return (MedianFinder*)malloc(sizeof(MedianFinder));
}
