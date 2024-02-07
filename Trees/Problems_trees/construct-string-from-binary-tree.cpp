#include <vector>
#include <string>
using namespace std;

// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    string ans;
    void preOrder(TreeNode* root) {
        if (root) {
            ans += to_string(root->val);

            if (root->left) {
                ans += "(";
                preOrder(root->left);
                ans += ")";
            } else if (root->right) {
                ans += "(";
                ans += ")";
            }

            if (root->right) {
                ans += "(";
                preOrder(root->right);
                ans += ")";
            }
        }
    }
    string tree2str(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};