// https://leetcode.com/problems/path-sum-ii/

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
    vector<int> temp;
    vector<vector<int>> arr;

    void pathSumRecur(TreeNode* node, int targetSum, int sum) {
        if (!node) return;

        sum += node->val;
        temp.push_back(node->val);

        if (!node->left && !node->right && sum == targetSum) {
            arr.push_back(temp);
            return;
        }

        if (node->left) {
            pathSumRecur(node->left, targetSum, sum);
            temp.pop_back();   
        }
        if (node->right) {
            pathSumRecur(node->right, targetSum,sum);        
            temp.pop_back();   
        }     
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        pathSumRecur(root, targetSum, 0);

        return arr;
    }
};

// In below implementation, we don't need to pop because everytime a copy of temp is sent in recursion.


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

    void pathSumRecur(TreeNode* node, int targetSum, int sum, vector<int> temp) {
        if (!node) return;

        sum += node->val;
        temp.push_back(node->val);

        if (!node->left && !node->right && sum == targetSum) {
            arr.push_back(temp);
            return;
        }

        pathSumRecur(node->left, targetSum, sum, temp);
        pathSumRecur(node->right, targetSum, sum, temp);        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        pathSumRecur(root, targetSum, 0, temp);

        return arr;
    }
};