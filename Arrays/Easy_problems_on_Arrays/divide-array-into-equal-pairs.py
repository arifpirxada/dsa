# https://leetcode.com/problems/divide-array-into-equal-pairs/

class Solution(object):
    def divideArray(self, nums):
        # checking if nums is even
        if len(nums) % 2 != 0:
            return False

        freq_dict = {}

        for num in nums:
            if num in freq_dict:
                freq_dict[num] += 1
            else:
                freq_dict[num] = 1

        for key, value in freq_dict.items():
            if value % 2 != 0:
                return False

        return True