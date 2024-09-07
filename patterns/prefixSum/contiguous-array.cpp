// https://leetcode.com/problems/contiguous-array/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxLength = 0;
        int cumulativeSum = 0;
        mp[0] = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                cumulativeSum += -1;
            } else {
                cumulativeSum += 1;
            }

            if (mp.find(cumulativeSum) != mp.end()) {
                maxLength = max(maxLength, i - mp[cumulativeSum]);
            } else {
                mp[cumulativeSum] = i;
            }
        }

        return maxLength;
    }
};