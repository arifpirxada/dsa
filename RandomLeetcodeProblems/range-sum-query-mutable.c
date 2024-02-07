// https://leetcode.com/problems/range-sum-query-mutable/




typedef struct {
    int *nums;
    int size;
    int sum;
} NumArray;


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray *obj = (NumArray*)malloc(sizeof(NumArray));
    obj->nums = nums;
    obj->size = numsSize;
    obj->sum = 0;

    for (int i = 0; i < numsSize; i++) {
        obj->sum += nums[i];
    }
    return obj;
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    obj->sum -= obj->nums[index];
    obj->sum += val;
    obj->nums[index] = val;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    int sum = obj->sum;
    int i = 0;

    while (i < left) {
        sum -= obj->nums[i];
        i++;
    }

    i = right + 1;
    while (i < obj->size) {
        sum -= obj->nums[i];
        i++;
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
 * numArrayUpdate(obj, index, val);
 
 * int param_2 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/