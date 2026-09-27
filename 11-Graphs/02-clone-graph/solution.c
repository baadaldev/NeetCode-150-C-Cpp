/**
 * LeetCode 133: Clone Graph
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
#include <stdlib.h>

struct Node {
    int val;
    int numNeighbors;
    struct Node** neighbors;
};

struct Node *cloneGraph(struct Node *s) {
    if (!s) return NULL;
    return s;
}
