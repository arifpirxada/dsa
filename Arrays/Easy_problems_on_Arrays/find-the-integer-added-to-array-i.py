# https://leetcode.com/problems/find-the-integer-added-to-array-i/

class Solution(object):
    def addedInteger(self, nums1, nums2):
        difference_count = {}
    
        for num1 in nums1:
            for num2 in nums2:
                difference = num2 - num1
                if difference in difference_count:
                    difference_count[difference] += 1
                else:
                    difference_count[difference] = 1
        
        max_difference = max(difference_count, key=difference_count.get)
        
        return max_difference
        