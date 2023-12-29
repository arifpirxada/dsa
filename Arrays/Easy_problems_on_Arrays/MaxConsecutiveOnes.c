// https://leetcode.com/problems/max-consecutive-ones/

int findMaxConsecutiveOnes(int* nums, int numsSize) {

    int i, times = 0, consec = 0;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            times++;
        } else {
            times = 0;
        }
        if (times > consec) {
            consec = times;
        }
    }

    return consec;
}