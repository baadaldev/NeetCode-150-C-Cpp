/**
 * LeetCode 121: Best Time to Buy and Sell Stock
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = 1e9, maxProf = 0;
        for (int p : prices) {
            minPrice = std::min(minPrice, p);
            maxProf = std::max(maxProf, p - minPrice);
        }
        return maxProf;
    }
};
