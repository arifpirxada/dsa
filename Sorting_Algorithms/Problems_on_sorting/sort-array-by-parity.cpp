#include <vector>
using namespace std;

// https://leetcode.com/problems/sort-array-by-parity/

class Solution {
public:
    void swap (int *a , int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    vector<int> sortArrayByParity(vector<int>& nums) {
        int i, j;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                break;
            }
        }

        for (j = i; j < nums.size(); j++) {
            if (nums[j] % 2 == 0) {
                swap(&nums[i], &nums[j]);
                i++;
            }
        }

        return nums;
    }
};