# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.lastNum = float('-inf')

    def isValidBST(self, root: TreeNode) -> bool:
        if(root):  # inorder
            if(not self.isValidBST(root.left)):
                return False
            if(root.val <= self.lastNum):
                return False
            self.lastNum = root.val
            if(not self.isValidBST(root.right)):
                return False
        return True
      
      
class Solution2:
    def isValidBST(self, root: TreeNode) -> bool:
        def compare(node, l, r):
            if not node:
                return True
            if node.val <= l or node.val >= r:
                return False
            return compare(node.left, l, node.val) and compare(node.right, node.val, r)
        return compare(root, float('-inf'), float('inf'))
