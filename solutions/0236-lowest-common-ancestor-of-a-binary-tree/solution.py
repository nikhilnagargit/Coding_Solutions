# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if root is q or root is p or not root: 
            return root
        a = self.lowestCommonAncestor(root.left,p,q)
        b = self.lowestCommonAncestor(root.right,p,q)
        if a and b:
            return root
        if a:
            return a
        return b
        
