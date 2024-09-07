// https://leetcode.com/problems/find-the-distinct-difference-array/

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int, int> left_count;
        unordered_map<int, int> right_count;
        vector<int> arr;
        int left = 0, right = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (right_count.find(nums[i]) != right_count.end()) {
                right_count[nums[i]]++;
            } else {
                right_count[nums[i]] = 1;
                right++;
            }
        }

        for (int i{}; i < nums.size(); i++) {
            if (left_count.find(nums[i]) != left_count.end()) {
                left_count[nums[i]]++;
            } else {
                left_count[nums[i]] = 1;
                left++;
            }

            if (right_count[nums[i]] == 1) {
                right--;
            }

            right_count[nums[i]]--;
            arr.push_back(left - right);
        }

        return arr;
    }
};