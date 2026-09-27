/**
 * LeetCode 763: Partition Labels
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> last(26, 0);
        for (int i = 0; i < (int)s.length(); ++i) last[s[i] - 'a'] = i;

        std::vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < (int)s.length(); ++i) {
            end = std::max(end, last[s[i] - 'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};
