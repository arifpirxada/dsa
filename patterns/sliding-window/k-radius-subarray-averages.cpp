// https://leetcode.com/problems/k-radius-subarray-averages/

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int i= 0, j = 0;
        long long sum = 0;
        vector<int> ans(nums.size(), -1);

        if (2 * k + 1 > nums.size()) return ans;

        while (j <= 2*k) {
            sum += nums[j];
            j++;
        }
        while (j < nums.size()) {
            ans[i + k] = sum / (2*k + 1);
            sum += nums[j];
            sum -= nums[i];
            j++;
            i++;
        }
        ans[i + k] = sum / (2 * k + 1);

        return ans;  
    }
};