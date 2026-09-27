/**
 * LeetCode 1584: Min Cost to Connect All Points
 * Time Complexity: O(V^2)
 * Space Complexity: O(V)
 */
#include <stdlib.h>
#include <stdbool.h>

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize) {
    int n = pointsSize;
    int* dist = (int*)malloc(n * sizeof(int));
    bool* visited = (bool*)calloc(n, sizeof(bool));
    for (int i = 0; i < n; i++) dist[i] = 1e9;
    dist[0] = 0;

    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) u = j;
        }
        visited[u] = true;
        totalCost += dist[u];
        for (int v = 0; v < n; v++) {
            if (!visited[v]) {
                int d = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                if (d < dist[v]) dist[v] = d;
            }
        }
    }
    free(dist);
    free(visited);
    return totalCost;
}
