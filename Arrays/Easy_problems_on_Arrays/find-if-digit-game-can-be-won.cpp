// https://leetcode.com/problems/find-if-digit-game-can-be-won/

class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleSum = 0, restSum = 0;

        for (int i{}; i < nums.size(); i++) {
            if (nums[i] < 10) {
                singleSum += nums[i];
            } else {
                restSum += nums[i];
            }
        }
        return singleSum != restSum;
    }
};