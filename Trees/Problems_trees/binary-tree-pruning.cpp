#include <stddef.h>

// https://leetcode.com/problems/binary-tree-pruning/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
right(right) {}
};

class Solution {
public:
    TreeNode* helper(TreeNode* root) {
        if (!root)
            return NULL;
        root->left = helper(root->left);
        root->right = helper(root->right);
        
        if (root->val != 1 && !root->left && !root->right) {
            return NULL;
        }
        return root;
    }
    TreeNode* pruneTree(TreeNode* root) { return helper(root); }
};