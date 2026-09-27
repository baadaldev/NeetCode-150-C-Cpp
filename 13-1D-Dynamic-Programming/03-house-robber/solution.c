/**
 * LeetCode 198: House Robber
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int rob(int* nums, int numsSize) {
    int rob1 = 0, rob2 = 0;
    for (int i = 0; i < numsSize; i++) {
        int temp = MAX(nums[i] + rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }
    return rob2;
}
