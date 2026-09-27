/**
 * LeetCode 124: Binary Tree Maximum Path Sum
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

static int maxGain(struct TreeNode* root, int* maxSum) {
    if (!root) return 0;
    int leftG = MAX(0, maxGain(root->left, maxSum));
    int rightG = MAX(0, maxGain(root->right, maxSum));
    int currentPath = root->val + leftG + rightG;
    if (currentPath > *maxSum) *maxSum = currentPath;
    return root->val + MAX(leftG, rightG);
}

int maxPathSum(struct TreeNode* root) {
    int maxSum = -1e9;
    maxGain(root, &maxSum);
    return maxSum;
}
