// https://leetcode.com/problems/maximum-erasure-value/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left = 0, right, sum = 0, curr_sum = 0;
        unordered_map<int, int> mp;

        for (right = 0; right < nums.size(); right++) {
            curr_sum += nums[right];
            mp[nums[right]]++;

            if (mp[nums[right]] == 2) {
                cout << left << " " << right << "; ";
                while (nums[left] != nums[right]) {
                    // cout << left << "; ";
                    mp[nums[left]]--;
                    curr_sum -= nums[left];
                    left++;
                }
                curr_sum -= nums[left];
                left++;
                mp[nums[right]]--;
            }
            sum = max(sum, curr_sum);
        }
        return sum;
    }
};