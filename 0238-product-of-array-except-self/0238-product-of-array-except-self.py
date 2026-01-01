class Solution(object):
    def productExceptSelf(self, nums):
        arr1 = [0] * len(nums)
        arr2 = [0] *len(nums)
        arr1[0] = 1
        arr2[len(nums)-1]=1
        for i in range(1 ,len(nums) ):
            arr1[i]=nums[i-1] *arr1[i-1]
        for i in range(len(nums)-2 , -1 , -1 ):
            arr2[i]=nums[i+1] *arr2[i+1]
        for i in range(len(nums)):
            nums[i]= arr1[i]*arr2[i]
        return nums



      
            
             