// https://leetcode.com/problems/running-sum-of-1d-array/

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int currSum = 0, n = nums.size();
        vector<int> runningSum(n);
        for (int i{}; i < n; i++) {
            currSum += nums[i];
            runningSum[i] = currSum;
        }
        return runningSum;
    }
};