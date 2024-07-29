# https://www.interviewbit.com/problems/repeat-and-missing-number-array/

class Solution:
    # @param A : tuple of integers
    # @return a list of integers
    def repeatedNumber(self, A):
        freq_dict = {}
        ans = []
        twoTimes = -1
        missing = -1
        
        for num in A:
            if num in freq_dict:
                freq_dict[num] += 1
            else:
                freq_dict[num] = 1
        
        n = len(A)
        
        for i in range(1, n + 1):
            if i in freq_dict:
                if freq_dict[i] == 2:
                    twoTimes = i
            else:
                missing = i
                
        ans.append(twoTimes)
        ans.append(missing)
        
        return ans