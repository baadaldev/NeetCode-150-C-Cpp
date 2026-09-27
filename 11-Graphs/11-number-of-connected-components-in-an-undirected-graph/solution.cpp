/**
 * LeetCode 323: Number of Connected Components
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
#include <vector>
#include <numeric>

class Solution {
    std::vector<int> parent;
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
public:
    int countComponents(int n, std::vector<std::vector<int>>& edges) {
        parent.resize(n);
        std::iota(parent.begin(), parent.end(), 0);
        int count = n;
        for (const auto& e : edges) {
            int r1 = find(e[0]), r2 = find(e[1]);
            if (r1 != r2) { parent[r1] = r2; count--; }
        }
        return count;
    }
};
