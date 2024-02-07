#include <vector>
#include <limits.h>
using namespace std;

// https://leetcode.com/problems/maximum-binary-tree/

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
    int findMaxIndex(vector<int>& nums, int left, int right) {
        int max = INT_MIN;
        int maxIndex = -1;

        for (int i = left; i <= right; i++) {
            if (nums[i] > max) {
                max = nums[i];
                maxIndex = i;
            }
        }

        return maxIndex;
    }

    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int maxIndex = findMaxIndex(nums, left, right);
        // Insert Node
        TreeNode* node = new TreeNode(nums[maxIndex]);
        
        node->left = helper(nums, left, maxIndex - 1);
        node->right = helper(nums, maxIndex + 1, right);

        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};