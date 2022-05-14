# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        pre = None
        curr = head
        while head.next:
            head = curr.next
            curr.next = pre
            pre = curr
            curr = head
        head.next = pre  # 记得最后还要接上
        return head
