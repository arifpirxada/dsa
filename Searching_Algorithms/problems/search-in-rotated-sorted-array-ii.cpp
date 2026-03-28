class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            while (low < mid && nums[mid] == nums[low]) {
                low++;
            }

            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] >= nums[low]) {
                if (nums[mid] > target && nums[low] <= target) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                if (nums[mid] < target && nums[high] >= target) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};