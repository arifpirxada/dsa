// https://leetcode.com/problems/kth-missing-positive-number/

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if (arr.size() == 1) {
            if (k < arr[0]) {
                return k;
            } else {
                return arr[0] + k - (arr[0] - 1);
            }
        }
        if (k < arr[0]) return k;
        // currMissing is the number of missing numbers to the left of current element
        int currMissing, nextCurrMissing, totalLeft = 0, n = arr.size();
        int low = 0, high = n - 1, mid;

        while (low <= high) {
            mid = (low + high) / 2;
            totalLeft = n - (n - mid - 1);
            currMissing = arr[mid] - totalLeft;
            if (mid >= n - 1) {
                nextCurrMissing = k + 1;
            } else {
                nextCurrMissing = arr[mid + 1] - (n - (n - mid - 1));
            }

            if (currMissing < k && nextCurrMissing > k) {
                int i = k - currMissing;
                return arr[mid] + i;
            } else if (currMissing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};