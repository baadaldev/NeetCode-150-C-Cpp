/**
 * LeetCode 54: Spiral Matrix
 * Time Complexity: O(m * n)
 * Space Complexity: O(1)
 */
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize, n = matrixColSize[0];
    int* res = (int*)malloc(m * n * sizeof(int));
    *returnSize = m * n;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;
    int idx = 0;

    while (top <= bottom && left <= right) {
        for (int c = left; c <= right; c++) res[idx++] = matrix[top][c];
        top++;
        for (int r = top; r <= bottom; r++) res[idx++] = matrix[r][right];
        right--;
        if (top <= bottom) {
            for (int c = right; c >= left; c--) res[idx++] = matrix[bottom][c];
            bottom--;
        }
        if (left <= right) {
            for (int r = bottom; r >= top; r--) res[idx++] = matrix[r][left];
            left++;
        }
    }
    return res;
}
