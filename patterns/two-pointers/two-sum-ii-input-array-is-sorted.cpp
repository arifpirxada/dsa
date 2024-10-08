// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (numbers[j] > target && numbers[0] > 0) {
            j--;
        }
        while (i <= j) {
            if (numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1};
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }
        return {};
    }
};