// https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int max_val = *max_element(nums.begin(), nums.end());
        int max_length = 0;
        int current_length = 0;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == max_val) {
                current_length++;
                max_length = max(max_length, current_length);
            } else {
                current_length = 0;
            }
        }

        return max_length;
    }
};