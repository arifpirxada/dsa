// https://leetcode.com/problems/sum-of-values-at-indices-with-k-set-bits/

class Solution {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int sum = 0;
        for (int i{}; i < nums.size(); i++) {
            if (countSetBits(i) == k) {
                sum += nums[i];
            }
        }
        return sum;
    }
};