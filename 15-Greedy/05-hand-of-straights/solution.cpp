/**
 * LeetCode 846: Hand of Straights
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <vector>
#include <map>

class Solution {
public:
    bool isNStraightHand(std::vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        std::map<int, int> count;
        for (int c : hand) count[c]++;

        for (auto [card, freq] : count) {
            if (freq > 0) {
                for (int i = 0; i < groupSize; ++i) {
                    if (count[card + i] < freq) return false;
                    count[card + i] -= freq;
                }
            }
        }
        return true;
    }
};
