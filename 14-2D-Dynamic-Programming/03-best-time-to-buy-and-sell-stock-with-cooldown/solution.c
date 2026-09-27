/**
 * LeetCode 309: Best Time to Buy and Sell Stock with Cooldown
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxProfit(int* prices, int pricesSize) {
    int hold = -1e9, sold = 0, rest = 0;
    for (int i = 0; i < pricesSize; i++) {
        int prevSold = sold;
        sold = hold + prices[i];
        hold = MAX(hold, rest - prices[i]);
        rest = MAX(rest, prevSold);
    }
    return MAX(sold, rest);
}
