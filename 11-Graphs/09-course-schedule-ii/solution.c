/**
 * LeetCode 210: Course Schedule II
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E)
 */
#include <stdlib.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++) inDegree[prerequisites[i][0]]++;

    int* q = (int*)malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q[tail++] = i;
    }
    int* order = (int*)malloc(numCourses * sizeof(int));
    int count = 0;
    while (head < tail) {
        int u = q[head++];
        order[count++] = u;
        for (int i = 0; i < prerequisitesSize; i++) {
            if (prerequisites[i][1] == u) {
                int v = prerequisites[i][0];
                if (--inDegree[v] == 0) q[tail++] = v;
            }
        }
    }
    free(inDegree);
    free(q);
    if (count == numCourses) {
        *returnSize = numCourses;
        return order;
    }
    *returnSize = 0;
    free(order);
    return NULL;
}
