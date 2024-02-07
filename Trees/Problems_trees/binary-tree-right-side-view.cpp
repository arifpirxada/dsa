#include <vector>
using namespace std;

// https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> ans;
    void helper(TreeNode *root, int depth) {
        if (!root) {
            return;
        }

        if (ans.size() <= depth) {
            ans.push_back(root->val);
        }

        helper(root->right, depth + 1);
        helper(root->left, depth + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        helper(root, 0);
        return ans;
    }
};