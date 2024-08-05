// https://leetcode.com/problems/left-and-right-sum-differences/

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int leftSum = 0, rightSum = 0, n = nums.size(), diff;
        vector<int> ans(n);

        // finding sum
        for (int i{}; i < n; i++) {
            rightSum += nums[i];
        }
        
        rightSum -= nums[0];
        ans[0] = rightSum;
        for (int i = 1; i < n; i++) {
            rightSum -= nums[i];
            leftSum += nums[i - 1];
            diff = abs(leftSum - rightSum);
            ans[i] = diff;
        }
        return ans;
    }
};