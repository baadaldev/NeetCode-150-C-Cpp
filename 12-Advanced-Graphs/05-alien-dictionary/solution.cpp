/**
 * LeetCode 269: Alien Dictionary
 * Time Complexity: O(C)
 * Space Complexity: O(1)
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

class Solution {
public:
    std::string alienOrder(std::vector<std::string>& words) {
        std::unordered_map<char, std::unordered_set<char>> adj;
        std::unordered_map<char, int> inDegree;
        for (const auto& w : words) for (char c : w) inDegree[c] = 0;

        for (size_t i = 0; i < words.size() - 1; ++i) {
            const std::string &w1 = words[i], &w2 = words[i + 1];
            size_t minLen = std::min(w1.length(), w2.length());
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) return "";
            for (size_t j = 0; j < minLen; ++j) {
                if (w1[j] != w2[j]) {
                    if (!adj[w1[j]].count(w2[j])) {
                        adj[w1[j]].insert(w2[j]);
                        inDegree[w2[j]]++;
                    }
                    break;
                }
            }
        }
        std::queue<char> q;
        for (auto [ch, deg] : inDegree) if (deg == 0) q.push(ch);

        std::string order;
        while (!q.empty()) {
            char u = q.front(); q.pop();
            order += u;
            for (char v : adj[u]) {
                if (--inDegree[v] == 0) q.push(v);
            }
        }
        return order.length() == inDegree.size() ? order : "";
    }
};
