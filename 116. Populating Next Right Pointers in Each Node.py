"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return None
        nodeQueue = [root]
        queueLen = 1
        while nodeQueue:
            for i in range(queueLen):
                node = nodeQueue.pop(0)
                if i < queueLen - 1:  # 否则到了层尾，为None
                    node.next = nodeQueue[0]
                if node.left:
                    nodeQueue.append(node.left)
                    nodeQueue.append(node.right)
            queueLen *= 2
        return root
                
