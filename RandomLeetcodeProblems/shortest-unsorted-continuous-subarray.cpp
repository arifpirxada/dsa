#include <vector>
using namespace std;

// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int first = 0, last = 0, max = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            if (max > nums[i]) {
                last = i;
            } else {
                max = nums[i];
            }
        }

        int min = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (min < nums[i]) {
                first = i;
            } else {
                min = nums[i];
            }
        }

        return (last == first) ? 0 : last - first + 1;
    }
};