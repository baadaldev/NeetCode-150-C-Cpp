/**
 * LeetCode 133: Clone Graph
 * Time Complexity: O(V + E)
 * Space Complexity: O(V)
 */
#include <vector>
#include <unordered_map>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node(int _val) : val(_val) {}
};

class Solution {
    std::unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (visited.count(node)) return visited[node];

        Node* clone = new Node(node->val);
        visited[node] = clone;
        for (auto n : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(n));
        }
        return clone;
    }
};
