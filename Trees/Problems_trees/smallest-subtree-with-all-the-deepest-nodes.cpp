// https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes

class Solution {
public:
    TreeNode* ans = NULL;
    int maxDepth = 0;

    int dfs(TreeNode* root, int depth) {
        if (!root) return depth - 1;

        int left = dfs(root->left, depth + 1);
        int right = dfs(root->right, depth + 1);

        int curDepth = max(left, right);

        if (left == right && curDepth >= maxDepth) {
            maxDepth = curDepth;
            ans = root;
        }

        return curDepth;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};