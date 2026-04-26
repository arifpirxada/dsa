// https://leetcode.com/problems/valid-elements-in-an-array/

class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        int leftMax = INT_MIN;

        vector<int> suffMax(n);
        suffMax[n - 1] = nums[n - 1];
        
        for (int i = n - 2; i > 0; i--) {
            suffMax[i] = max(suffMax[i + 1], nums[i]);
        }
        
        for (int i = 0; i < n; i++) {
            if (i == 0 || i == n - 1) {
                ans.push_back(nums[i]);
            } else if (nums[i] > leftMax || nums[i] > suffMax[i + 1]) {
                ans.push_back(nums[i]);
            }
            leftMax = max(leftMax, nums[i]);
        }
        return ans;
    }
};