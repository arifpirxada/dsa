// https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        long curr_sum = 0;
        int min_length = INT_MAX;
        if (nums[0] >= target) return 1;
        if (nums.size() <= 1) return 0;

        while (j < nums.size()) {
            curr_sum += nums[j];
            while (curr_sum >= target) {
                if (j - i + 1 < min_length) min_length = j - i + 1;
                curr_sum -= nums[i];
                i++;
            }
            j++;
        }
        return (min_length == INT_MAX ? 0 : min_length);
    }
};