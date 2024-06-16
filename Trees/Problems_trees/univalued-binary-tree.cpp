// https://leetcode.com/problems/univalued-binary-tree/

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
    int uniValued = 1;
    void helper(TreeNode* root, int value) {
        if (!root) return;
        if (root->val != value) {
            uniValued = 0;
            return;
        }
        helper(root->left, value);
        helper(root->right, value);
    }
    bool isUnivalTree(TreeNode* root) {
        if (root) {
            helper(root, root->val);
            return uniValued;
        } else {
            return true;
        }
    }
};