# https://leetcode.com/problems/degree-of-an-array/

class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # Dictionary to store the frequency of each element
        freq_dict = {}
        # Dictionary to store the first occurrence of each element
        first_occurrence = {}
        # Dictionary to store the last occurrence of each element
        last_occurrence = {}
        
        for i, num in enumerate(nums):
            if num not in freq_dict:
                freq_dict[num] = 1
                first_occurrence[num] = i
            else:
                freq_dict[num] += 1
            last_occurrence[num] = i
        
        # Determine the degree of the array
        max_freq = max(freq_dict.values())
        
        # Find the smallest subarray length with the same degree
        min_length = len(nums)
        for num, freq in freq_dict.items():
            if freq == max_freq:
                min_length = min(min_length, last_occurrence[num] - first_occurrence[num] + 1)
        
        return min_length