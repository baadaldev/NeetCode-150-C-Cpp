/**
 * LeetCode 121: Best Time to Buy and Sell Stock
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 */
int maxProfit(int* prices, int pricesSize) {
    if (pricesSize <= 1) return 0;
    int minPrice = prices[0];
    int maxProf = 0;
    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProf) {
            maxProf = prices[i] - minPrice;
        }
    }
    return maxProf;
}
