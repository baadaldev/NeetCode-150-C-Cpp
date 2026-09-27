/**
 * LeetCode 323: Number of Connected Components
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
int countComponents(int n, int** edges, int edgesSize, int* edgesColSize) {
    int parent[2005];
    for (int i = 0; i < n; i++) parent[i] = i;
    int find(int x) { return parent[x] == x ? x : (parent[x] = find(parent[x])); }
    int count = n;
    for (int i = 0; i < edgesSize; i++) {
        int p1 = find(edges[i][0]), p2 = find(edges[i][1]);
        if (p1 != p2) { parent[p1] = p2; count--; }
    }
    return count;
}
