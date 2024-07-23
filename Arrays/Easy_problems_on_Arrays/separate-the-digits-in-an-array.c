// https://leetcode.com/problems/separate-the-digits-in-an-array/

int* separateDigits(int* nums, int numsSize, int* returnSize) {
    // Getting size
 
    int size = 0;
    char tempStr[20];

    for (int i = 0; i < numsSize; i++) {
        sprintf(tempStr, "%d", nums[i]);
        int len = strlen(tempStr);
        size += len;
        if (tempStr[0] == '-') {
            size -= 1;
        }
    }

    int* result = (int*)malloc(size * sizeof(int));
    int k = 0;

    for (int i = 0; i < numsSize; i++) {
        sprintf(tempStr, "%d", nums[i]);
        int j = 0;
        int len = strlen(tempStr);
        if (tempStr[0] == '-') {
            j++;
        }
        while (j < len) {
            result[k++] = tempStr[j] - '0';
            j++;
        }
    }

    *returnSize = size;
    return result;
}