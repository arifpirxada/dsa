// https://leetcode.com/problems/flip-equivalent-binary-trees/

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
    bool helper(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return root1 == root2;

        if (root1->val != root2->val) {
            return false;
        }
        bool case1 = helper(root1->left, root2->left) && helper(root1->right, root2->right);
        bool case2 = helper(root1->left, root2->right) && helper(root1->right, root2->left);

        return case1 || case2;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return helper(root1, root2);
    }
};