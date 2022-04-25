# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False
        nodeList = set([head])
        while head.next:
            if head.next not in nodeList:
                head = head.next
                nodeList.add(head)
            else:
                return True
        return False
        
class Solution1:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head:
            return False
        fast = head
        slow = head
        while fast.next and fast.next.next:  # 无需判断slow
            slow = slow.next
            fast = fast.next.next
            if fast == slow:
                return True
        return False
