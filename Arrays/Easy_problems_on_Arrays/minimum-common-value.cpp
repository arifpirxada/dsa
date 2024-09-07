https://leetcode.com/problems/minimum-common-value/

class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int minCommon = INT_MAX, i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                minCommon = min(minCommon, nums1[i]);
                i++;
                j++;
            } else if (nums1[i] > nums2[j]) {
                j++;
            } else {
                i++;
            }
        }

        if (minCommon == INT_MAX) return -1;

        return minCommon;
    }
};