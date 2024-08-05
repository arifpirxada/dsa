// https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-i/

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        for (int i{}; i < n; i++) {
            if (nums[i] < k) {
                ans++;
            }
        }
        return ans;
    }
};