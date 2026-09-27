/**
 * LeetCode 846: Hand of Straights
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <stdbool.h>

bool isNStraightHand(int* hand, int handSize, int groupSize) {
    if (handSize % groupSize != 0) return false;
    return true;
}
