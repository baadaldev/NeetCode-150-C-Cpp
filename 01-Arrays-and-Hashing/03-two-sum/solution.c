/**
 * LeetCode 1: Two Sum
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>

typedef struct HashNode {
    int key;
    int val;
    struct HashNode* next;
} HashNode;

#define HASH_SIZE 10007

static unsigned int hash(int key) {
    return (unsigned int)(key % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashNode* table[HASH_SIZE] = {0};
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        unsigned int h = hash(complement);
        HashNode* curr = table[h];
        while (curr) {
            if (curr->key == complement) {
                result[0] = curr->val;
                result[1] = i;
                return result;
            }
            curr = curr->next;
        }
        unsigned int hn = hash(nums[i]);
        HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
        newNode->key = nums[i];
        newNode->val = i;
        newNode->next = table[hn];
        table[hn] = newNode;
    }
    *returnSize = 0;
    return NULL;
}
