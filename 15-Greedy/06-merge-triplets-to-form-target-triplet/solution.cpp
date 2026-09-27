/**
 * LeetCode 1899: Merge Triplets to Form Target Triplet
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>

class Solution {
public:
    bool mergeTriplets(std::vector<std::vector<int>>& triplets, std::vector<int>& target) {
        bool has0 = false, has1 = false, has2 = false;
        for (const auto& t : triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                if (t[0] == target[0]) has0 = true;
                if (t[1] == target[1]) has1 = true;
                if (t[2] == target[2]) has2 = true;
            }
        }
        return has0 && has1 && has2;
    }
};
