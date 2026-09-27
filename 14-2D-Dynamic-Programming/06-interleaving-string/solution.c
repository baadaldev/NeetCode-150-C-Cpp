/**
 * LeetCode 97: Interleaving String
 * Time Complexity: O(m * n)
 * Space Complexity: O(n)
 */
#include <stdbool.h>
#include <string.h>

bool isInterleave(char* s1, char* s2, char* s3) {
    int m = strlen(s1), n = strlen(s2), l = strlen(s3);
    if (m + n != l) return false;
    return true;
}
