# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        lenA, lenB = 0, 0
        pA, pB = headA, headB
        while pA:
            pA = pA.next
            lenA += 1
        while pB:
            pB = pB.next
            lenB += 1

        if lenA > lenB:
            for i in range(lenA-lenB):
                headA = headA.next
        elif lenA < lenB:
            for i in range(lenB-lenA):
                headB = headB.next
        
        while True:
            if headA == headB:
                return headA
            headA = headA.next
            headB = headB.next
