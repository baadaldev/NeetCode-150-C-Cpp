/**
 * LeetCode 763: Partition Labels
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int* partitionLabels(char* s, int* returnSize) {
    int last[26];
    int len = strlen(s);
    for (int i = 0; i < len; i++) last[s[i] - 'a'] = i;

    int* res = (int*)malloc(len * sizeof(int));
    int size = 0, start = 0, end = 0;

    for (int i = 0; i < len; i++) {
        end = MAX(end, last[s[i] - 'a']);
        if (i == end) {
            res[size++] = end - start + 1;
            start = i + 1;
        }
    }
    *returnSize = size;
    return res;
}
