// https://leetcode.com/problems/delete-node-in-a-bst

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
    TreeNode* getPredecessor(TreeNode* node) {
        node = node->left;
        while (node && node->right) {
            node = node->right;
        }
        return node;
    }
    TreeNode* getSuccessor(TreeNode* node) {
        node = node->right;
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Leaf Case
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            } else {
                TreeNode* pre = getPredecessor(root);
                if (pre) {
                    root->val = pre->val;
                    pre->val = key;
                    root->left = deleteNode(root->left, pre->val);
                } else {
                    TreeNode* suc = getSuccessor(root);
                    root->val = suc->val;
                    suc->val = key;
                    root->right = deleteNode(root->right, suc->val);
                }
            }
        }

        return root;
    }
};