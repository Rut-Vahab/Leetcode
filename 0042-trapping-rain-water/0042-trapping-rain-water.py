class Solution:
    def trap(self, height: List[int]) -> int:
        max1 = 0
        count = 0 
        end = 0 
        index = 0 
        for i ,val in enumerate(height) :
            if val > max1:
                max1 = val 
                index = i
        for i in range(index):
            if  height[i]>end :
                end = height[i] 
            count += (end -height[i] )
        end = 0 
        for i in range( len(height)-1, index ,-1):
            if height[i] > end :
                end = height[i] 
            count+=(end -height[i] )
        return count
            
        


        
        