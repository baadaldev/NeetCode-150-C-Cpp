/**
 * LeetCode 213: House Robber II
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

static int robHelper(int* nums, int start, int end) {
    int rob1 = 0, rob2 = 0;
    for (int i = start; i <= end; i++) {
        int temp = MAX(nums[i] + rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    return rob2;
}

int rob(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    return MAX(robHelper(nums, 0, numsSize - 2), robHelper(nums, 1, numsSize - 1));
}
