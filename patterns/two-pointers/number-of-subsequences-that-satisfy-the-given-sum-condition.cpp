// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, result = 0, MOD = 1e9 + 7;
        vector<int> power(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            power[i] = (power[i - 1] * 2) % MOD;
        }
        sort(nums.begin(), nums.end());

        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                result = (result + power[r - l]) % MOD;
                l++;
            } else {
                r--;
            }
        }
        return result;
    }
};