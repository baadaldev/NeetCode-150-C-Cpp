/**
 * LeetCode 136: Single Number
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int singleNumber(int* nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; i++) res ^= nums[i];
    return res;
}
