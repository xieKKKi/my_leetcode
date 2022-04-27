# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def merge(self, head1, head2):  # 两个有序链表的合并
        if head1.val < head2.val:
            head = head1
            head1 = head1.next
        else:
            head = head2
            head2 = head2.next
        p = head
        while head1 and head2:
            if head1.val <= head2.val:
                p.next = head1
                p = p.next
                head1 = head1.next
            else:
                p.next = head2
                p = p.next
                head2 = head2.next
        while head1:
            p.next = head1
            p = p.next
            head1 = head1.next
        while head2:
            p.next = head2
            p = p.next
            head2 = head2.next
        return head
    def sortList(self, head):
        fast, slow, slowPre = head, head, None  # 快慢指针找中间节点
        while fast and fast.next:
            fast = fast.next.next
            slowPre = slow
            slow = slow.next
        if slow == head:
            return head  # 只有一个节点或者没有节点
        else:
            slowPre.next = None  # 断开两段的连接
        return self.merge(self.sortList(head), self.sortList(slow))

