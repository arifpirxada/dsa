// https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() == 1) return true;
        int i;
        for (i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                break;
            }
        }
        if (i >= nums.size()) return true;
        if (nums[i] > nums[0]) {
            return false;
        }
        i++;
        while (i < nums.size()) {
            if (nums[i] > nums[0] || nums[i] < nums[i - 1]) {
                return false;
            }
            i++;
        }
        return true;
    }
};