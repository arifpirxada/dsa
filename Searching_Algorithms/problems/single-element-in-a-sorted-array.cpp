class Solution {
public:
    int getLeftSize(vector<int>& nums, int mid, int len) {
        if (mid == 0) return 0;
        if (nums[mid] == nums[mid - 1]) {
            return -1 + mid;
        } else {
            return 0 + mid;
        }
    }
    bool isSingle(vector<int>& nums, int mid, int len) {
        if (mid > 0 && nums[mid] == nums[mid - 1]) {
            return false;
        } else if (mid < len && nums[mid] == nums[mid + 1]) {
            return false;
        }
        return true;
    }
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return nums[0];
        int l = 0, r = len - 1, mid;

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (isSingle(nums, mid, len)) {
                return nums[mid];
            } else if (getLeftSize(nums, mid, len) % 2 == 0) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return -1;
    }
};

// Clean optimal simple written solution, above solution is also optimal but a little complicated

/*
💡 Key Insight (Important)

In a sorted array where every element appears twice except one:

👉 Before the single element: pairs start at even index
👉 After the single element: pairs start at odd index
*/


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            // Ensure mid is even
            if (mid % 2 == 1) mid--;

            if (nums[mid] == nums[mid + 1]) {
                l = mid + 2;
            } else {
                r = mid;
            }
        }

        return nums[l];
    }
};