class Solution {
public:
    int findMin(vector<int>& arr) {
        int low = 0, high = arr.size() - 1, mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (mid > 0 && arr[mid] < arr[mid - 1]) {
                return arr[mid];
            } else if (arr[mid] < arr[low]) {
                high = mid - 1;
            } else {
                if (arr[mid] > arr[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return arr[0];
    }
};