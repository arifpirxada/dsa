// https://leetcode.com/problems/maximum-depth-of-binary-tree/

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
    int maxRec(TreeNode* node, int currDepth) {
        if (node == NULL) return currDepth;

        currDepth++;
        
        int leftDepth = maxRec(node->left, currDepth);
        int rightDepth = maxRec(node->right, currDepth);

        return max(leftDepth, rightDepth);
    }
    int maxDepth(TreeNode* root) {
        return maxRec(root, 0);
    }
};