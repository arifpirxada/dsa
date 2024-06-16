// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

class Solution {
public:
    long long total = 0;
    void numsSum(vector<int>& nums) {
        for (auto i : nums) total += i;
    }
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        numsSum(nums);

        for (int i = n - 1; i >= 0; i--) {
            if (total - nums[i] > nums[i]) return total;
            total -= nums[i];
        }
        return -1;
    }
};