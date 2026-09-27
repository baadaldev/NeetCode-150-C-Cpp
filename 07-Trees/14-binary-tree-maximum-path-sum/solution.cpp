/**
 * LeetCode 124: Binary Tree Maximum Path Sum
 * Time Complexity: O(n)
 * Space Complexity: O(h)
 */
#include <algorithm>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int maxSum = INT_MIN;
    int maxGain(TreeNode* root) {
        if (!root) return 0;
        int l = std::max(0, maxGain(root->left));
        int r = std::max(0, maxGain(root->right));
        maxSum = std::max(maxSum, root->val + l + r);
        return root->val + std::max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
