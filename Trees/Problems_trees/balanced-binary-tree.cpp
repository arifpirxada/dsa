// https://leetcode.com/problems/balanced-binary-tree/

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
    int balRecur(TreeNode* node, int depth) {
        if (node == NULL) return depth;

        depth++;
        int leftDepth = balRecur(node->left, depth);
        int rightDepth = balRecur(node->right, depth);

        if (leftDepth == -1 || rightDepth == -1) {
            return -1;
        }
        else if (abs(leftDepth - rightDepth) <= 1) {
            return max(leftDepth, rightDepth);
        } else {
            return -1;
        }
    }
    bool isBalanced(TreeNode* root) {
        int result = balRecur(root, 0);
        if (result == -1) return false;
        return true;
    }
};


// Cleaner and good way - no depth

class Solution {
public:
    int balRecur(TreeNode* node) {
        if (node == NULL) return 0;

        int leftDepth = balRecur(node->left);
        if (leftDepth == -1) return -1;

        int rightDepth = balRecur(node->right);
        if (rightDepth == -1) return -1;

        if (abs(leftDepth - rightDepth) > 1)
            return -1;

        return 1 + max(leftDepth, rightDepth);
    }

    bool isBalanced(TreeNode* root) {
        return balRecur(root) != -1;
    }
};