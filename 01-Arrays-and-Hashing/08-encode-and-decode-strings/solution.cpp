/**
 * LeetCode 271 / LintCode 659: Encode and Decode Strings
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <string>
#include <vector>

class Solution {
public:
    std::string encode(const std::vector<std::string>& strs) {
        std::string encoded;
        for (const auto& s : strs) {
            encoded += std::to_string(s.length()) + '#' + s;
        }
        return encoded;
    }

    std::vector<std::string> decode(const std::string& s) {
        std::vector<std::string> decoded;
        size_t i = 0;
        while (i < s.length()) {
            size_t hashPos = s.find('#', i);
            int len = std::stoi(s.substr(i, hashPos - i));
            decoded.push_back(s.substr(hashPos + 1, len));
            i = hashPos + 1 + len;
        }
        return decoded;
    }
};
