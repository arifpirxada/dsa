#include <stdio.h>
#include <stdlib.h>

// Given an array of integers nums and an integer target, 
// return indices of the two numbers such that they add up to target.
// Link: "https://leetcode.com/problems/two-sum/"

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int main()
{
    int nums[] = {2, 7, 11, 15}, target = 9, returnSize, i;
    int *result = twoSum(nums, 4, target, &returnSize);

    for (i = 0; i < returnSize; i++)
    {
        printf("Index: %d\n", result[i]);
    }

    free(result);

    return 0;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{

    int *result = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < numsSize; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;

                *returnSize = 2;

                return result;
            }
        }
    }

    *returnSize = 0;
    return 0;
}

// optimized c++ solution

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> mp;

//         for (int i{}; i < nums.size(); i++) {
//             if (mp.find(target - nums[i]) == mp.end()) {
//                 mp[nums[i]] = i;
//             } else {
//                 return {mp[target - nums[i]], i};
//             }
//         }

//         return {-1, -1};
//     }
// };