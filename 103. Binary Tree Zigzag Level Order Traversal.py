# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        nodeQueue = [root]
        result = []
        direction = False
        while nodeQueue:
            tmp = []
            for i in range(len(nodeQueue)):
                node = nodeQueue.pop(0)
                tmp.append(node.val)
                if direction:
                    if node.right:
                        nodeQueue.append(node.right)
                    if node.left:
                        nodeQueue.append(node.left)
                else:
                    if node.left:
                        nodeQueue.append(node.left)
                    if node.right:
                        nodeQueue.append(node.right)
            result.append(tmp)
            direction = not direction
            #nodeQueue = list(reversed(nodeQueue))
            nodeQueue = nodeQueue[::-1]
        return result
