/**
 * LeetCode 684: Redundant Connection
 * Time Complexity: O(n * alpha(n))
 * Space Complexity: O(n)
 */
#include <stdlib.h>

static int findRoot(int* parent, int i) {
    if (parent[i] == i) return i;
    return parent[i] = findRoot(parent, parent[i]);
}

int* findRedundantConnection(int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    int parent[1005];
    for (int i = 0; i < 1005; i++) parent[i] = i;

    int* res = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        int rootU = findRoot(parent, u);
        int rootV = findRoot(parent, v);
        if (rootU == rootV) {
            res[0] = u; res[1] = v;
            return res;
        }
        parent[rootU] = rootV;
    }
    return res;
}
