# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        left = 0 
        dummy = ListNode(0)
        l3 = dummy
        while l1 is not None or l2 is not  None  or left !=0 :
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0
            result = val1 + val2 + left 
            left = result //10
           
            l3.next = ListNode(result%10)
            l3 = l3.next
            
            if l1 : l1=l1.next
            if l2:  l2= l2.next

        return dummy.next   
            
        


            

         
        