class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        dic= {}
        maxLangs = 0 
        current = 0
        start = 0 
        for i , val in enumerate(s):
            if val not in dic :
                dic[val]= i 
            else :
                if start <= dic[val] :
                    start = dic[val]+1
                dic[val] =i
            current= i - start+1           
            if current > maxLangs:
                maxLangs =current 
        return maxLangs




        