/**
 * LeetCode 684: Redundant Connection
 * Time Complexity: O(n * alpha(n))
 * Space Complexity: O(n)
 */
#include <vector>
#include <numeric>

class Solution {
    std::vector<int> parent;
    int find(int i) {
        return parent[i] == i ? i : parent[i] = find(parent[i]);
    }
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        std::iota(parent.begin(), parent.end(), 0);

        for (const auto& e : edges) {
            int rootU = find(e[0]), rootV = find(e[1]);
            if (rootU == rootV) return e;
            parent[rootU] = rootV;
        }
        return {};
    }
};
