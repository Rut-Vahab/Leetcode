class Solution:
    def myAtoi(self, s: str) -> int:
        negative = False 
        num = 0 
        s = s.lstrip()
        for i, char  in enumerate(s):
            if s[i] is   "-" and i is  0 :
                negative = True
            elif s[i] == "+" and i == 0: 
                continue
                print("dd")
            elif s[i].isdigit() :
                print (char)
                if char == "0" and num == 0 :
                    continue
                num = num*10
                num += int(char)
            else : 
                break
      
        if negative :
            num = num*-1
        INT_MAX = 2**31 - 1
        INT_MIN = -2**31
        if num > INT_MAX:
            return INT_MAX
        if num < INT_MIN:
            return INT_MIN

        return num

        
        return num


       


        