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
    int gk;
    int inorder(TreeNode* node) {
        if (!node) return NULL;

        int left = inorder(node->left);

        if (left) {
            return left;
        } else {
            gk--;
            if (gk == 0) return node->val;
        } 

        int right = inorder(node->right);

        if (right) {
            return right;
        }
        return NULL;
    }
    int kthSmallest(TreeNode* root, int k) {
        gk = k;
        return inorder(root);
    }
};