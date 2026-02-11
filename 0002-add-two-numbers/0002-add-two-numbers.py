class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)  # node עזר כדי לא לאבד את הראש
        l3 = dummy
        left = 0

        while l1 or l2 or left:
            val1 = l1.val if l1 else 0
            val2 = l2.val if l2 else 0

            result = val1 + val2 + left
            left = result // 10  # carry
            digit = result % 10  # הספרה שתיכנס ל-node החדש

            l3.next = ListNode(digit)
            l3 = l3.next

            if l1: l1 = l1.next
            if l2: l2 = l2.next

        return dummy.next
