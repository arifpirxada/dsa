// https://leetcode.com/problems/subarray-sum-equals-k/
// https://www.youtube.com/watch?v=-SWrz90jCUM

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int count = 0, prefixSum = 0;
        mp[0] = 1;

        for (int i{}; i < nums.size(); i++) {
            prefixSum += nums[i];

            if (mp.find(prefixSum - k) != mp.end()) {
                count += mp[prefixSum - k];
            }
            mp[prefixSum]++;
        }
        return count;
    }
};