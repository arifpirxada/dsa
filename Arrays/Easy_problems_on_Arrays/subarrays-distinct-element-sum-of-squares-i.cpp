// https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int count = 0;

        for (int i{}; i < nums.size(); i++) {
            int currCount = 0;
            unordered_map<int, int> mp;
            for (int j = i; j < nums.size(); j++) {
                if (mp.find(nums[j]) == mp.end()) {
                    currCount++;
                    mp[nums[j]] = 1;
                }
                count += currCount * currCount;
            }
        }

        return count;
    }
};