// https://leetcode.com/problems/path-sum/

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
    bool getSum(TreeNode* node, int targetSum, int currSum) {
        if (node == NULL) return false;

        currSum += node->val;

        if (currSum == targetSum && node->left == NULL && node->right == NULL) {
            return true;
        }

        bool left = getSum(node->left, targetSum, currSum);
        bool right = getSum(node->right, targetSum, currSum);

        if (left == true || right == true) {
            return true;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return getSum(root, targetSum, 0);
    }
};

// Another way of implementation, but time and space complexity same

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;

    // If leaf node
    if (!root->left && !root->right) {
        return targetSum == root->val;
    }

    int remaining = targetSum - root->val;

    return hasPathSum(root->left, remaining) ||
            hasPathSum(root->right, remaining);
}