// https://leetcode.com/problems/find-common-elements-between-two-arrays/

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        for (int num: nums1) {
            mp1[num]++;
        }
        for (int num: nums2) {
            mp2[num]++;
        }

        vector<int> arr(2, 0);
        for (int num: nums1) {
            if (mp2.find(num) != mp2.end()) {
                arr[0]++;
            }
        }
        for (int num: nums2) {
            if (mp1.find(num) != mp1.end()) {
                arr[1]++;
            }
        }
        return arr;
    }
};