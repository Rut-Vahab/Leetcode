class Solution(object):
    def longestConsecutive(self, nums):
        numset = set(nums)
        max1 = 0 
        for num in numset : 
            if num-1 not in numset:
                courrent = num
                count=1
                while courrent+1 in numset:
                    courrent+=1
                    count+=1
                max1 =max(max1, count)
        return max1


        


    