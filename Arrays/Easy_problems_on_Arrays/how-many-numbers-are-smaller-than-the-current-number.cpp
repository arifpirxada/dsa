// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;
        unordered_map<int, int> mp;

        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0; i--) {
            mp[v[i]] = i;
        }

        for (int i = 0; i < n; i++) {
            nums[i] = mp[nums[i]];
        }
        return nums;
    }
};