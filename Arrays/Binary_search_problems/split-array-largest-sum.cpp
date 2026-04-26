// https://leetcode.com/problems/split-array-largest-sum

class Solution {
public:
    int countSplit(vector<int>& nums, int m) {
        int splits = 1;
        int curr = 0;
        for (int num : nums) {
            if (curr + num <= m) {
                curr += num;
            } else {
                curr = num;
                splits++;
            }
        }
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(), nums.end());
        int r = accumulate(nums.begin(), nums.end(), 0);
        int m;

        while (l <= r) {
            m = l + (r - l) / 2;

            if (countSplit(nums, m) > k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l;
    }
};