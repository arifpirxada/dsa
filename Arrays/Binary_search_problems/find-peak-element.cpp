class Solution {
public:
    bool isPeak(vector<int>& nums, int m, int n) {
        if (m == 0 && nums[m] > nums[m + 1]) {
            return true;
        } else if (m == n - 1 && nums[m] > nums[m - 1]) {
            return true;
        } else if (m > 0 && m < n -1 && nums[m] > nums[m - 1] && nums[m] > nums[m + 1]) {
            return true;
        }
        return false;
    }
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, m;

        if (n == 1) return 0; 

        while (l <= r) {
            m = l + (r - l) / 2;
            if (isPeak(nums, m, n)) {
                return m;
            } else if (nums[m + 1] > nums[m] && nums[l] < nums[m + 1]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return -1;
    }
};

// Well Written

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] < nums[m + 1])
                l = m + 1;
            else
                r = m;
        }

        return l;
    }
};