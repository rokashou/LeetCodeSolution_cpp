/* 112. Path Sum */
/* 0ms, 21.46MB */

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
    bool hasPathSum(TreeNode *root, int targetSum) {
        // Base case: empty tree has no valid path
        if (root == nullptr) return false;

        // Subtract current node's value from the remaining target
        int remaining = targetSum - root->val;

        // If it's a leaf node, check whether the remaining sum is exactly zero
        if (root->left == nullptr && root->right == nullptr) {
            return remaining == 0;
        }

        // Otherwise, recurse into children with the updated remaining sum
        return hasPathSum(root->left, remaining) || hasPathSum(root->right, remaining);

    }
};
