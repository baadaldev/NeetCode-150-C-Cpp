/**
 * LeetCode 11: Container With Most Water
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int maxWater = 0;
    while (left < right) {
        int h = MIN(height[left], height[right]);
        int currentWater = h * (right - left);
        if (currentWater > maxWater) maxWater = currentWater;
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxWater;
}
