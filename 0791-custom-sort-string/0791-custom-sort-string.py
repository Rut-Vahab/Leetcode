class Solution(object):
    def customSortString(self, order, s):
        result = ""
        order_list = list(order)
        s_list =  list(s)
        for i in order_list:
            if i in s_list:
                print (i , s_list.count(i))
                for j in range (s_list.count(i)):
                    result+= i 
        print(result)
        for i in s_list:
            if i not in order_list:
                result+= i 
        return result
        