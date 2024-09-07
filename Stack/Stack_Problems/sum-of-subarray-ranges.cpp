// https://leetcode.com/problems/sum-of-subarray-ranges/

// Brute force
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int currMin, currMax;
        long long totalRange = 0;

        for (int i{}; i < nums.size(); i++) {
            currMin = nums[i], currMax = nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                currMin = min(currMin, nums[j]);
                currMax = max(currMax, nums[j]);
                totalRange += currMax - currMin;
            }
        }

        return totalRange;
    }
};