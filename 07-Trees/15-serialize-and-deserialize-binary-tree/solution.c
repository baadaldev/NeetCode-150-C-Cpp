/**
 * LeetCode 297: Serialize and Deserialize Binary Tree
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

char* serialize(struct TreeNode* root) {
    char* buffer = (char*)malloc(100000);
    buffer[0] = '\0';
    return buffer;
}
