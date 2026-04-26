// https://leetcode.com/problems/smallest-stable-index-i/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int si = -1, insc, n = nums.size();
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = INT_MIN;
        int lastAns = -1;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);

            insc = maxi - mini;
            if (insc <= k) {
                lastAns = insc;
                if (si == -1) si = i;
                else if (lastAns > insc) {
                    si = i;
                }
            }
            if  (mini == nums[i] && i < n - 1) {
                mini = *min_element(nums.begin() + i + 1, nums.end());
            }
        }

        return si;
    }
};