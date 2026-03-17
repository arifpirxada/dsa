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
    vector<vector<int>> arr;

    int getDepth(TreeNode* node, int depth){
        if (!node) return depth;

        depth++;
        int left = getDepth(node->left, depth);
        int right = getDepth(node->right, depth);

        return max(left, right);
    }

    void fill(TreeNode* node, int level) {
        if (!node) return;

        fill(node->left, level - 1);
        arr[level].push_back(node->val);
        fill(node->right, level - 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int depth = getDepth(root, 0);

        for (int i = 0; i < depth; i++) {
            arr.push_back({});
        }

        fill(root, depth - 1);
        return arr;   
    }
};