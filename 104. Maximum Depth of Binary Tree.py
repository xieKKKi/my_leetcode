# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        nodeQueue = [root]
        depth = 0
        while nodeQueue:
            for i in range(len(nodeQueue)):
                node = nodeQueue.pop(0)
                if node.left:
                    nodeQueue.append(node.left)
                if node.right:
                    nodeQueue.append(node.right)
            depth += 1
        return depth


class Solution2:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return max(1+self.maxDepth(root.left), 1+self.maxDepth(root.right))
