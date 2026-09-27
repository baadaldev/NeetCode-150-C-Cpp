/**
 * LeetCode 66: Plus One
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        digits[i] = 0;
    }
    int* res = (int*)malloc((digitsSize + 1) * sizeof(int));
    res[0] = 1;
    for (int i = 1; i <= digitsSize; i++) res[i] = 0;
    *returnSize = digitsSize + 1;
    return res;
}
