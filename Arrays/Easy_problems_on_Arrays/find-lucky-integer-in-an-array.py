# https://leetcode.com/problems/find-lucky-integer-in-an-array/

class Solution(object):
    def findLucky(self, arr):
         freq_dict = {}
         for num in arr:
             if num in freq_dict:
                 freq_dict[num] += 1
             else:
                 freq_dict[num] = 1

         largest = float('-inf')
         for key, value in freq_dict.items():
             if key == value:
                 if key > largest:
                    largest = key

         if largest == float('-inf'):
            return -1
         
         return largest