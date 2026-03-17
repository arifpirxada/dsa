/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool isParent(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (
            (node->val > p->val && node->val < q->val) ||
            (node->val > q->val && node->val < p->val) ||
            (node->val == p->val || node->val == q->val)
        ) {
            return true;
        }
        return false;
    }
    TreeNode* find(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) return NULL;

        if (isParent(node, p, q)) {
            return node;
        }

        TreeNode* left = find(node->left, p, q);
        if (left) return left;

        TreeNode* right = find(node->right, p, q);
        return right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root, p, q);
    }
};