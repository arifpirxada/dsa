// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        
        int low = 0, high = n - 1;
        int firstPositiveIndex = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > 0) {
                firstPositiveIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        low = 0, high = n - 1;
        int lastNegativeIndex = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] < 0) {
                lastNegativeIndex = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        int posCount = n - firstPositiveIndex;
        int negCount = lastNegativeIndex + 1;
        
        return max(posCount, negCount);
    }
};