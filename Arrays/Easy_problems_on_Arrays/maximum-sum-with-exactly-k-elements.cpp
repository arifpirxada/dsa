// https://leetcode.com/problems/maximum-sum-with-exactly-k-elements/

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi = nums[0], sum = 0;

        for (int i{}; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }

        for (int i = 0; i < k; i++) {
            sum += maxi + i;
        }

        return sum;
    }
};