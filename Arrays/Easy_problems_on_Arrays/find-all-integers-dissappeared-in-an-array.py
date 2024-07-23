# https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

class Solution(object):
    def findDisappearedNumbers(self, nums):
        nums_dict = {}

        for num in nums:
            if num not in nums_dict:
                nums_dict[num] = 1
        
        result = []
        for i in range(1, len(nums) + 1):
            if i not in nums_dict:
                result.append(i)
        
        return result