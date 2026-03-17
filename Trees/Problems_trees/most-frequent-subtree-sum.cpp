https://leetcode.com/problems/most-frequent-subtree-sum/

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
    unordered_map<int, int> sums;
    int high_freq = 0;

    int getSum(TreeNode* node) {
        if (!node) return 0;

        int left = getSum(node->left);
        int right = getSum(node->right);

        int sum = node->val + left + right;

        if (sums.find(sum) != sums.end()) {
            sums[sum] += 1;
        } else {
            sums[sum] = 1;
        }

        high_freq = max(high_freq, sums[sum]);

        return sum;
    };

    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;

        getSum(root);

        for (auto &p : sums) {
            if (p.second == high_freq) {
                ans.push_back(p.first);
            }
        }
        return ans;
    }
};