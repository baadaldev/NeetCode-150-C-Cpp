/**
 * LeetCode 45: Jump Game II
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int jump(int* nums, int numsSize) {
    int jumps = 0, curEnd = 0, farthest = 0;
    for (int i = 0; i < numsSize - 1; i++) {
        farthest = MAX(farthest, i + nums[i]);
        if (i == curEnd) {
            jumps++;
            curEnd = farthest;
        }
    }
    return jumps;
}
