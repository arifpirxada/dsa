// https://leetcode.com/problems/compare-sums-of-bitonic-parts

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        long long leftSum = 0, rightSum = 0;
        int i = 0, n = nums.size();
        
        while (i < n) {
            leftSum += nums[i];
            if (nums[i] == maxi) break;
            i++;
        }
        while (i < n) {
            rightSum += nums[i];
            i++;
        }

        if (leftSum == rightSum) return -1;
        if (leftSum > rightSum) return 0;
        return 1;
    }
};