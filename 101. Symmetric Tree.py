# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetricLR(self, rootL, rootR):
        if not rootL and not rootR:
            return True
        elif rootL and rootR:
            return rootL.val == rootR.val and \
                self.isSymmetricLR(rootL.left, rootR.right) and self.isSymmetricLR(rootL.right, rootR.left)
        else:
            return False
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        return self.isSymmetricLR(root.left, root.right)
        
