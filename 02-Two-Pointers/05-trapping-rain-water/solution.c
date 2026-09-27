/**
 * LeetCode 42: Trapping Rain Water
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int trap(int* height, int heightSize) {
    if (heightSize <= 2) return 0;
    int l = 0, r = heightSize - 1;
    int leftMax = 0, rightMax = 0, total = 0;

    while (l < r) {
        if (height[l] < height[r]) {
            if (height[l] >= leftMax) leftMax = height[l];
            else total += leftMax - height[l];
            l++;
        } else {
            if (height[r] >= rightMax) rightMax = height[r];
            else total += rightMax - height[r];
            r--;
        }
    }
    return total;
}
