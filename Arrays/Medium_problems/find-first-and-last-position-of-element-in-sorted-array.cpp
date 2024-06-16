// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> ans;
    void binarySearch(vector<int>& arr, int arrUsedSize, int element) {
        int low = 0, mid, high = arrUsedSize - 1;

        while (low <= high) {
            mid = (low + high) / 2;
            if (arr[mid] == element) {
                int start = mid;
                while (start > 0 && arr[start - 1] == element) {
                    start--;
                }

                int end = mid;
                while (end < arrUsedSize - 1 && arr[end + 1] == element) {
                    end++;
                }

                ans.push_back(start);
                ans.push_back(end);
                return;
            } else if (arr[mid] < element) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        ans.push_back(-1);
        ans.push_back(-1);
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        binarySearch(nums, nums.size(), target);
        return ans;
    }
};