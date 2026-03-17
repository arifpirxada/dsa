// https://leetcode.com/problems/find-largest-value-in-each-tree-row/

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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int len = q.size();
            int level_max = INT_MIN;
            for (int i = 0; i < len; i++) {
                TreeNode* f = q.front();
                q.pop();

                level_max = max(level_max, f->val);

                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
            ans.push_back(level_max);
        }

        return ans;
    }
};