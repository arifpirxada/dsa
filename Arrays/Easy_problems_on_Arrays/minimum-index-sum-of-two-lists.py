# leetcode.com/problems/minimum-index-sum-of-two-lists/

class Solution(object):
    def findRestaurant(self, list1, list2):
        index_dict = {}
        common_dict = {}

        i = 0
        for item in list1:
            if item not in index_dict:
                index_dict[item] = i
            i += 1
        
        i = 0
        for item in list2:
            if item in index_dict:
                common_dict[item] = index_dict[item] + i
            i += 1

        least_index_sum = 2000
        common_string = []

        for key, value in common_dict.items():
            if value < least_index_sum:
                least_index_sum = value
                common_string = [key]
            elif value == least_index_sum:
                common_string.append(key)
        
        return common_string   