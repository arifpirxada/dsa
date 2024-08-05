// https://leetcode.com/problems/sort-colors/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        mp[0] = 0;
        mp[1] = 0;
        mp[2] = 0;

        for (int i{}; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        for (int i{}; i < mp[0]; i++) {
            ans.push_back(0);
        }
        for (int i{}; i < mp[1]; i++) {
            ans.push_back(1);
        }
        for (int i{}; i < mp[2]; i++) {
            ans.push_back(2);
        }

        // copy elements
        for (int i{}; i < nums.size(); i++) {
            nums[i] = ans[i];
        }
    }
};