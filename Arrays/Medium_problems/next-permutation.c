// https://leetcode.com/problems/next-permutation/
// https://www.youtube.com/watch?v=JDOXKqF60RQ

void reverseSubArrayFromIndex(int arr[], int start, int n) {
    int end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    int ind = -1;

    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] < nums[i+1]) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        reverseSubArrayFromIndex(nums, 0, numsSize);
        return;
    }
    for (int i = numsSize - 1; i > ind; i--) {
        if (nums[i] > nums[ind]) {
            // Swap elements
            int temp = nums[i];
            nums[i] = nums[ind];
            nums[ind] = temp;
            break;
        }
    }

    reverseSubArrayFromIndex(nums, ind + 1, numsSize);
}