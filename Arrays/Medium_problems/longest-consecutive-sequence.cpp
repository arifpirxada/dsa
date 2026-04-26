class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxi = 0;

        for (int num : numSet) {
            if (!numSet.count(num - 1)) {
                int cur = num;
                int len = 1;
                while (numSet.count(cur + 1)) {
                    cur++;
                    len++;
                }
                maxi = max(maxi, len);
            }
        }
        return maxi;
    }
};