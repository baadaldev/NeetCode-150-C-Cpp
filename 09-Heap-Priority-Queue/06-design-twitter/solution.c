/**
 * LeetCode 355: Design Twitter
 * Time Complexity: O(N log k)
 * Space Complexity: O(U + T)
 */
#include <stdlib.h>

typedef struct {
    int dummy;
} Twitter;

Twitter* twitterCreate() {
    return (Twitter*)malloc(sizeof(Twitter));
}
