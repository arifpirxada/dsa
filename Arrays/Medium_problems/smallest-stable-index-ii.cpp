// https://leetcode.com/problems/smallest-stable-index-ii/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int insc, n = nums.size();
        int mini;
        int maxi = INT_MIN;
        vector<int> sufMin(n);

        sufMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sufMin[i] = min(nums[i], sufMin[i + 1]);
        }

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            mini = sufMin[i];

            insc = maxi - mini;
            if (insc <= k) {
                return i;
            }

        }

        return -1;
    }
};