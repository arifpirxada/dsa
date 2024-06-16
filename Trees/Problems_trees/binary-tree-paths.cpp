#include <vector>
#include <string.h>
#include <string>
using namespace std;

// https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> ans;
    void helper(TreeNode* root, string currPath) {
        if (root) {
            // Add current node's value to the current path
            currPath += to_string(root->val);

            // If it's not a leaf node, continue with "->"
            if (root->left || root->right) {
                currPath += "->";
                helper(root->left, currPath);
                helper(root->right, currPath);
            } else {
                // If it's a leaf node, add the current path to the result
                ans.push_back(currPath);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root) {
            helper(root, "");
        }
        return ans;
    }
};