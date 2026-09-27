/**
 * LeetCode 347: Top K Frequent Elements
 * Time Complexity: O(n log n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>

typedef struct {
    int val;
    int count;
} Freq;

static int cmp(const void* a, const void* b) {
    return ((Freq*)b)->count - ((Freq*)a)->count;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), (int(*)(const void*, const void*))cmp);
    // Frequency tabulation and sort
    Freq* freqs = (Freq*)malloc(numsSize * sizeof(Freq));
    int count = 0;
    for (int i = 0; i < numsSize; ) {
        int j = i;
        while (j < numsSize && nums[j] == nums[i]) j++;
        freqs[count].val = nums[i];
        freqs[count].count = j - i;
        count++;
        i = j;
    }
    qsort(freqs, count, sizeof(Freq), cmp);
    int* res = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++) {
        res[i] = freqs[i].val;
    }
    *returnSize = k;
    free(freqs);
    return res;
}
