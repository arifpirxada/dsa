// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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

// # My solution - but O(N^2) for worst case (skewed) because traveses for everynode.

class Solution {
public:
    TreeNode* preorder(TreeNode* node) {
        if (node == NULL) return NULL;

        TreeNode* left = preorder(node->left);
        TreeNode* right = preorder(node->right);

        if (left == NULL) return node;

        node->right = left;
        node->left = NULL;

        while (left->right != NULL) {
            left = left->right;
        }
        left->right = right;

        return node;
    }
    void flatten(TreeNode* root) {
        preorder(root);
    }
};

// Reverse Order (Best Recursive Solution)

// 🔥 Time: O(N)
// 🔥 Space: O(H) (recursion stack)

class Solution {
public:
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if (root == NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// Morris Traversal (Most Optimal – O(1) Space)

// 🔥 Time: O(N)
// 🔥 Space: O(1)

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr != NULL) {
            if (curr->left != NULL) {

                TreeNode* pred = curr->left;
                while (pred->right != NULL) {
                    pred = pred->right;
                }

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }

            curr = curr->right;
        }
    }
};