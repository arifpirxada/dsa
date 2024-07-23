// https://leetcode.com/problems/number-of-unequal-triplets-in-array/

int hasTriplet(int* nums, int numsSize, int index) {
    int triplets = 0;
    for (int i = index + 1; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[index] != nums[i] && nums[index] != nums[j] && nums[i] != nums[j]) {
                triplets++;
            }
        }
    }

    return triplets;
}

int unequalTriplets(int* nums, int numsSize) {
    int num_of_triplets = 0;
    int triplets;

    for (int i = 0; i < numsSize; i++) {
        triplets = hasTriplet(nums, numsSize, i);
        num_of_triplets += triplets;
    }

    return num_of_triplets;
}