// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/

int findSpecialInteger(int* arr, int arrSize) {
    int fourthPart = arrSize / 4, i, times = 1;
    for (i = 0; i < arrSize - 1; i++) {
        // Check if the current element is the same as the next one
        if (arr[i] == arr[i + 1]) {
            times++;
        } else {
            times = 1; // Reset frequency if different element
        }

        // Check if the current element occurs more than 25% of the time
        if (times > fourthPart) {
            return arr[i];
        }
    }

    // Return the last element if it occurs more than 25% of the time
    return arr[arrSize - 1];
}