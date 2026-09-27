/**
 * LeetCode 49: Group Anagrams
 * Time Complexity: O(n * k log k)
 * Space Complexity: O(n * k)
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (const auto& s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            map[key].push_back(s);
        }
        std::vector<std::vector<std::string>> result;
        result.reserve(map.size());
        for (auto& pair : map) {
            result.push_back(std::move(pair.second));
        }
        return result;
    }
};
