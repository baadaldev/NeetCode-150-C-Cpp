/**
 * LeetCode 207: Course Schedule
 * Time Complexity: O(V + E)
 * Space Complexity: O(V + E)
 */
#include <stdbool.h>
#include <stdlib.h>

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int* inDegree = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++) inDegree[prerequisites[i][0]]++;

    int* q = (int*)malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;
    for (int i = 0; i < numCourses; i++) {
        if (inDegree[i] == 0) q[tail++] = i;
    }
    int visited = 0;
    while (head < tail) {
        int u = q[head++];
        visited++;
        for (int i = 0; i < prerequisitesSize; i++) {
            if (prerequisites[i][1] == u) {
                int v = prerequisites[i][0];
                if (--inDegree[v] == 0) q[tail++] = v;
            }
        }
    }
    free(inDegree);
    free(q);
    return visited == numCourses;
}
