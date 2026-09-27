/**
 * LeetCode 268: Missing Number
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int missingNumber(int* nums, int numsSize) {
    int res = numsSize;
    for (int i = 0; i < numsSize; i++) {
        res ^= i ^ nums[i];
    }
    return res;
}
