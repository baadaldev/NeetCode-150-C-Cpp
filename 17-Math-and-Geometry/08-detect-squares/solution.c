/**
 * LeetCode 2013: Detect Squares
 * Time Complexity: add O(1), count O(N)
 * Space Complexity: O(N)
 */
#include <stdlib.h>

typedef struct {
    int grid[1001][1001];
} DetectSquares;

DetectSquares* detectSquaresCreate() {
    return (DetectSquares*)calloc(1, sizeof(DetectSquares));
}

void detectSquaresAdd(DetectSquares* obj, int* point, int pointSize) {
    obj->grid[point[0]][point[1]]++;
}

int detectSquaresCount(DetectSquares* obj, int* point, int pointSize) {
    int px = point[0], py = point[1];
    int total = 0;
    for (int x = 0; x <= 1000; x++) {
        if (x == px) continue;
        int side = abs(px - x);
        int y1 = py + side;
        if (y1 <= 1000) {
            total += obj->grid[x][py] * obj->grid[px][y1] * obj->grid[x][y1];
        }
        int y2 = py - side;
        if (y2 >= 0) {
            total += obj->grid[x][py] * obj->grid[px][y2] * obj->grid[x][y2];
        }
    }
    return total;
}
