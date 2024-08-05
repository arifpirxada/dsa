// https://leetcode.com/problems/create-target-array-in-the-given-order/

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n = nums.size();
        vector<int> ans;

        for (int i{}; i < n; i++) {
            ans.insert(ans.begin() + index[i], nums[i]);
        }
        return ans;
    }
};