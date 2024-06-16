// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int helper(TreeNode* root, int sum) {
        if (!root) return sum;

        root->val += helper(root->right, sum);
        sum = root->val;
        
        return helper(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        helper(root, 0);
        return root;
    }
};