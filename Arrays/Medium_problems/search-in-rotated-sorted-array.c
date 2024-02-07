// https://leetcode.com/problems/search-in-rotated-sorted-array/

int search(int* nums, int numsSize, int target) {
    int low = 0, mid, high = numsSize - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] >= nums[low]) {

            if (nums[mid] < target || target < nums[low]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        } else {

            if (target < nums[mid] || target > nums[high]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
    }

    return -1;
}