// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        if (root == NULL) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool isLeftRight = true; 

        while(!q.empty()) {
            int len = q.size();
            vector<int> level;
            for (int i = 0; i < len; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (isLeftRight) {
                    level.push_back(node->val);
                } else {
                    level.insert(level.begin(), node->val);
                }
                if(node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            isLeftRight = !isLeftRight;
            result.push_back(level);
        }

        return result;
    }
};