// https://leetcode.com/problems/product-of-array-except-self/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int i;
    
    int* leftProducts = (int*)malloc(numsSize * sizeof(int));
    int* rightProducts = (int*)malloc(numsSize * sizeof(int));
    
    // Initialize leftProducts array
    leftProducts[0] = 1;
    for (i = 1; i < numsSize; i++) {
        leftProducts[i] = leftProducts[i - 1] * nums[i - 1];
    }
    
    // Initialize rightProducts array
    rightProducts[numsSize - 1] = 1;
    for (i = numsSize - 2; i >= 0; i--) {
        rightProducts[i] = rightProducts[i + 1] * nums[i + 1];
    }
    
    // Calculate the final result
    int* ans = (int*)malloc(numsSize * sizeof(int));
    for (i = 0; i < numsSize; i++) {
        ans[i] = leftProducts[i] * rightProducts[i];
    }
    
    // Set the xreturn size and free the allocated memory
    *returnSize = numsSize;
    free(leftProducts);
    free(rightProducts);
    
    return ans;
}

// Below is a solution using division - which is wrong as mentioned in question.
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int i, j, totalProduct = 1, tempProduct = 1;
    int *ans = (int*)malloc(numsSize *sizeof(int));

    // calculate total product

    for(i = 0; i < numsSize; i++) {
        totalProduct *= nums[i];
    }

    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            for (j = 0; j < numsSize; j++) {
                if (j == i) {
                    continue;
                }
                tempProduct *= nums[j];
            }
            ans[i] = tempProduct;
            continue;
        }
        ans[i] = totalProduct / nums[i];
    }

    *returnSize = numsSize;
    return ans;
}