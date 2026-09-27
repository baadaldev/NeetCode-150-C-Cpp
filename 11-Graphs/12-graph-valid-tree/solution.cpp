/**
 * LeetCode 261: Graph Valid Tree
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
#include <vector>
#include <numeric>

class Solution {
    std::vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
public:
    bool validTree(int n, std::vector<std::vector<int>>& edges) {
        if ((int)edges.size() != n - 1) return false;
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        for (const auto& e : edges) {
            int r1 = find(e[0]), r2 = find(e[1]);
            if (r1 == r2) return false;
            parent[r1] = r2;
        }
        return true;
    }
};
