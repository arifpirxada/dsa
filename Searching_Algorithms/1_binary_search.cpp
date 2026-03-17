#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int st = 0, end = arr.size() - 1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            st = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int bsLowerBound(vector<int>& arr, int target) {
    int st = 0, end = arr.size() - 1;
    int ans = arr.size();

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] >= target) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return ans;
}

int bsUpperBound(vector<int>& arr, int target) {
    int st = 0, end = arr.size() - 1;
    int ans = arr.size();

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] > target) {
            ans = mid;
            end = mid - 1;
        } else {
            st = mid + 1;
        }
    }

    return ans;
}

int lastOccurrence(vector<int>& arr, int target) {
    int st = 0, end = arr.size() - 1;
    int ans = -1;

    while (st <= end) {
        int mid = st + (end - st) / 2;

        if (arr[mid] <= target) {
            ans = mid;
            st = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int index = binarySearch(arr, 3, 0, arr.size() - 1);

    cout << "Index: " << index;

    return 0;
}