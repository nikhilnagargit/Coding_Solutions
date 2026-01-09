# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        def deepestCount(root):
            level = 0
            dq = deque([root])
            while dq:
                count = len(dq)
                l = len(dq)
                level+=1
                for i in range(0,l):
                    curr = dq.popleft()
                    if curr.right:
                        dq.append(curr.right)
                    if curr.left:
                        dq.append(curr.left)
            return count,level

        def deepestCountCheck(root,currLevel,targetLevel):
            level = currLevel
            if not root:
                return -1
            dq = deque([root])
            while dq:
                level+=1
                count = len(dq)
                l = len(dq)
                for i in range(0,l):
                    curr = dq.popleft()
                    if curr.right:
                        dq.append(curr.right)
                    if curr.left:
                        dq.append(curr.left)
            if level!=targetLevel:
                return -1
            return count

        deepestLevelItemsCount,deepestLevel = deepestCount(root)
        def lca(root,level):
            nonlocal deepestLevelItemsCount
            nonlocal deepestLevel
            # check for left subtree
            if not root:
                return root
            if deepestCountCheck(root.left,level+1,deepestLevel)==deepestLevelItemsCount:
                return lca(root.left,level+1)
            if deepestCountCheck(root.right,level+1,deepestLevel)==deepestLevelItemsCount:
                return lca(root.right,level+1)
            return root
        
        return lca(root,0)

                



    
            


