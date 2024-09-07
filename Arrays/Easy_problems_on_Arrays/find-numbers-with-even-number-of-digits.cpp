// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        string temp;

        for (int i{}; i < nums.size(); i++) {
            temp = to_string(nums[i]);
            if (temp.size() % 2 == 0) {
                count++;
            }
        }
        return count;
    }
};