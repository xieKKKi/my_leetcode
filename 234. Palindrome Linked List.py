# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head:
            return True
        fast, slow, pre = head, head, None
        while fast and fast.next:
            fast = fast.next.next
            # 反转slow经过的链表
            temp = slow
            slow = slow.next
            temp.next = pre
            pre = temp
        
        if fast:
            slow = slow.next

        while slow:
            if slow.val != pre.val:
                return False
            slow = slow.next
            pre = pre.next
        return True
