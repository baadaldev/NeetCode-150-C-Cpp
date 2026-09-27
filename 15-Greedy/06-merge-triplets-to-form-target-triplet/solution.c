/**
 * LeetCode 1899: Merge Triplets to Form Target Triplet
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stdbool.h>

bool mergeTriplets(int** triplets, int tripletsSize, int* tripletsColSize, int* target, int targetSize) {
    bool has0 = false, has1 = false, has2 = false;
    for (int i = 0; i < tripletsSize; i++) {
        int a = triplets[i][0], b = triplets[i][1], c = triplets[i][2];
        if (a <= target[0] && b <= target[1] && c <= target[2]) {
            if (a == target[0]) has0 = true;
            if (b == target[1]) has1 = true;
            if (c == target[2]) has2 = true;
        }
    }
    return has0 && has1 && has2;
}
