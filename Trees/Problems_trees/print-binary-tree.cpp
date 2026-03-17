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
    vector<vector<string>> res;
    int getHeight(TreeNode* root) {
        if (root == nullptr)
            return -1;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        return 1 + max(leftHeight, rightHeight);
    }
    void fill(TreeNode* root, int h, int r, int c) {
        if (!root) return;

        res[r][c] = to_string(root->val);

        if (r == h) return;

        fill(root->left, h, r + 1, c - (1 << (h - r - 1)));
        fill(root->right, h, r + 1, c + (1 << (h - r - 1)));
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = getHeight(root);
        int m = h + 1;
        int n = (1 << (h + 1)) - 1;

        res.resize(m, vector<string>(n, ""));
 
        fill(root, h, 0, (n-1)/2);

        return res;        
    }
};