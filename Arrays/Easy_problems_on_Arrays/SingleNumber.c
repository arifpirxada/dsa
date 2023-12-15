// https://leetcode.com/problems/single-number/

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int nums[], int low, int high) {
    int pivot = nums[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (nums[j] <= pivot) {
            i++;
            swap(&nums[i], &nums[j]);
        }
    }

    swap(&nums[i + 1], &nums[high]);
    return i + 1;
}

void quickSort(int nums[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(nums, low, high);

        quickSort(nums, low, pivotIndex - 1);
        quickSort(nums, pivotIndex + 1, high);
    }
}

int singleNumber(int* nums, int numsSize) {
    int i;
    quickSort(nums, 0, numsSize - 1);
    for (i = 1; i < numsSize; i += 2) {
        if (nums[i] != nums[i - 1]) {
            return nums[i - 1];
        }
    }
    return nums[numsSize - 1];
}