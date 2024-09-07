// https://leetcode.com/problems/range-sum-query-immutable/


// Previous solution c++ code

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

// New using prefix sum:

class NumArray {
private:
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        prefix.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            prefix.push_back(prefix.back() + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return left > 0 ? (prefix[right] - prefix[left - 1]) : prefix[right];
    }
};