/**
 * LeetCode 309: Best Time to Buy and Sell Stock with Cooldown
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int hold = -1e9, sold = 0, rest = 0;
        for (int p : prices) {
            int prevSold = sold;
            sold = hold + p;
            hold = std::max(hold, rest - p);
            rest = std::max(rest, prevSold);
        }
        return std::max(sold, rest);
    }
};
