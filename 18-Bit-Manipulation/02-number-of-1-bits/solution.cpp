/**
 * LeetCode 191: Number of 1 Bits
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */
#include <cstdint>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            n &= (n - 1);
            count++;
        }
        return count;
    }
};
