/**
 * LeetCode 875: Koko Eating Bananas
 * Time Complexity: O(n log(max(piles)))
 * Space Complexity: O(1)
 */
#include <stdbool.h>

static bool canEatAll(int* piles, int pilesSize, int h, int k) {
    long long hours = 0;
    for (int i = 0; i < pilesSize; i++) {
        hours += (piles[i] + k - 1) / k;
    }
    return hours <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int maxPile = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > maxPile) maxPile = piles[i];
    }
    int left = 1, right = maxPile, ans = maxPile;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canEatAll(piles, pilesSize, h, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}
