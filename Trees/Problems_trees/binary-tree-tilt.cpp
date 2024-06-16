#include <stdlib.h>
// https://leetcode.com/problems/binary-tree-tilt/

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
public:
    int ans = 0;
    int helper(TreeNode* root) {
        if (!root) return 0;

        int leftSum = helper(root->left);
        int rightSum = helper(root->right);

        int diff = abs(rightSum - leftSum);
        ans += diff;

        root->val += leftSum + rightSum;
        return root->val;
    }
    int findTilt(TreeNode* root) {
        helper(root);
        return ans;
    }
};
