// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1, n = nums.size();
        if (n > 1 && nums[1] == nums[0]) {
            k++;
        }
        for (int i = k; i < n; i++) {
            if (nums[i] != nums[i-1]) {
                nums[k] = nums[i];
                k++;
                if (i < n - 1 && nums[i] == nums[i + 1]) {
                    nums[k] = nums[i + 1];
                    k++;
                }
            }
        }
        return k;
    }
};