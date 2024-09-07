// https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/

class Solution {
public:
    int getMin(vector<int> nums) {
        int mini = nums[0], minIndex = 0;
        for (int i{}; i < nums.size(); i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i{}; i < k; i++) {
            int index = getMin(nums);
            nums[index] = nums[index] * multiplier;
        }
        return nums;
    }
};