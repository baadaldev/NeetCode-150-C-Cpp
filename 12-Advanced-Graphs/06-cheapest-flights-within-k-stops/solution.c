/**
 * LeetCode 787: Cheapest Flights Within K Stops
 * Time Complexity: O(K * E)
 * Space Complexity: O(V)
 */
#include <string.h>

int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int k) {
    int prices[105];
    for (int i = 0; i < n; i++) prices[i] = 1e9;
    prices[src] = 0;

    for (int i = 0; i <= k; i++) {
        int temp[105];
        memcpy(temp, prices, n * sizeof(int));
        for (int j = 0; j < flightsSize; j++) {
            int u = flights[j][0], v = flights[j][1], w = flights[j][2];
            if (prices[u] != 1e9 && prices[u] + w < temp[v]) {
                temp[v] = prices[u] + w;
            }
        }
        memcpy(prices, temp, n * sizeof(int));
    }
    return prices[dst] == 1e9 ? -1 : prices[dst];
}
