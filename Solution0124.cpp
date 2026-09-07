/* 124. Binary Tree Maximum Path Sum */
/* Given a binary tree, find the maximum path sum. */
/* Runtime: 0ms, Memory: 27.82MB */


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxSum = INT_MIN;
        maxGain(root, maxSum);
        return maxSum;
    }

private:

    /** Returns the maximum downward path sum starting at 'node',
     * which is the value that can be extended upward to its parent.
     */
    int maxGain(TreeNode *node, int &maxSum) {
        if (node == nullptr) return 0;

        // Discard negative gains from children (treat as 0)
        int leftGain = std::max(maxGain(node->left, maxSum), 0);
        int rightGain = std::max(maxGain(node->right, maxSum), 0);

        // Best path sum with 'node' as the turning point (highest point)
        int priceNewPath = node->val + leftGain + rightGain;
        maxSum = std::max(maxSum, priceNewPath);

        // 返回經過 node 且向上傳遞的最大貢獻值
        return node->val + std::max(leftGain, rightGain);
    }
};
