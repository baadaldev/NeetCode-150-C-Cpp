/**
 * LeetCode 167: Two Sum II - Input Array Is Sorted
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int left = 0, right = numbersSize - 1;
    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    while (left < right) {
        int sum = numbers[left] + numbers[right];
        if (sum == target) {
            res[0] = left + 1;
            res[1] = right + 1;
            return res;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    *returnSize = 0;
    return NULL;
}
