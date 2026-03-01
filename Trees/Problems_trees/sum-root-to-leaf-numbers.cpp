// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    vector<int> sums;
    void sumRecur(TreeNode* node, int temp) {
        if (!node) return;

        temp = (temp * 10) + node->val;

        if (!node->left && !node->right) {
            sums.push_back(temp);
        }

        if (node->left)
            sumRecur(node->left, temp);
        
        if (node->right)
            sumRecur(node->right, temp);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;

        sumRecur(root, 0);

        for(int i = 0; i < sums.size(); i++) {
            ans += sums[i];
        }
        return ans;
    }
};

// Beats 100%;

class Solution {
public:
    int sum = 0;
    void sumRecur(TreeNode* node, int temp) {
        if (!node) return;
        temp = (temp * 10) + node->val;

        if (!node->left && !node->right) {
            sum += temp;
        }
        sumRecur(node->left, temp);
        sumRecur(node->right, temp);
    }
    int sumNumbers(TreeNode* root) {

        sumRecur(root, 0);

        return sum;
    }
};