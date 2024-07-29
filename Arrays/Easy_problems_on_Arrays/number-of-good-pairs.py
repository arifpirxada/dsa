# https://leetcode.com/problems/number-of-good-pairs/

class Solution(object):
    def numIdenticalPairs(self, nums):
        freq_dict = {}
        
        for num in nums:
            if num in freq_dict:
                freq_dict[num] += 1
            else:
                freq_dict[num] = 1

        goodPairs = 0

        for key, value in freq_dict.items():
            goodPairs += value * (value - 1) / 2
        
        return goodPairs