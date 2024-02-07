#include <vector>
using namespace std;

// https://leetcode.com/problems/sort-even-and-odd-indices-independently/

class Solution {
public:
    std::vector<int> sortEvenOdd(std::vector<int>& nums) {
        for (std::size_t i = 0, k = 1; i < nums.size(); i += 2, k += 2) {
            for (std::size_t j = i + 2, l = k + 2; j < nums.size(); j += 2, l += 2) {
                if (nums[i] > nums[j]) {
                    std::swap(nums[i], nums[j]);
                }

                if (nums[k] < nums[l]) {
                    std::swap(nums[k], nums[l]);
                }
            }
        }

        return nums;
    }
};