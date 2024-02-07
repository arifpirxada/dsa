#include <vector>
using namespace std;

// https://leetcode.com/problems/sort-an-array/

class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        int i = low, j = mid + 1;
        vector<int> tempArr;

        while (i <= mid && j <= high) {
            if (arr[i] < arr[j]) {
                tempArr.push_back(arr[i]);
                i++;
            } else {
                tempArr.push_back(arr[j]);
                j++;
            }
        }

        while (i <= mid) {
            tempArr.push_back(arr[i]);
            i++;
        }

        while (j <= high) {
            tempArr.push_back(arr[j]);
            j++;
        }

        // Copy elements back
        for (i = low, j = 0; i <= high; i++, j++) {
            arr[i] = tempArr[j];
        }
    }

    void mergeSort(vector<int>& arr, int low, int high) {
        int mid;
        if (low < high) {
            mid = (low + high) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};