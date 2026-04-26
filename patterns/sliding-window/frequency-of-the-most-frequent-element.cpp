// https://leetcode.com/problems/frequency-of-the-most-frequent-element/

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0, n = nums.size();
        long long windowSum = 0, ans = 0;

        for (int j = 0; j < n; j++) {
            windowSum += nums[j];

            while ((long long)nums[j] * (j - i + 1) - windowSum > k) {
                windowSum -= nums[i];
                i++;
            }

            ans = max(ans, (long long)(j - i + 1));
        }

        return ans;
    }
};