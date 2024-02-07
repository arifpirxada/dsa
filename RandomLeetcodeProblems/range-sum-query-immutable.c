// https://leetcode.com/problems/range-sum-query-immutable/




typedef struct {
    int *nums;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray*)malloc(sizeof(NumArray));
    obj->nums = nums;
    return obj;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sum = 0;

    while (left <= right) {
        sum += obj->nums[left];
        left++;
    }
    return sum;
}

void numArrayFree(NumArray* obj) {
    free(obj->nums);
    free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/