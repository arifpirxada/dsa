// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int elementSum = 0, digitSum = 0;

        for (int i{}; i < nums.size(); i++) {
            elementSum += nums[i];
            while (nums[i] != 0) {
                digitSum += nums[i] % 10;
                nums[i] /= 10;
            }
        }

        return abs(elementSum - digitSum);
    }
};