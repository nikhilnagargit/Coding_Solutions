# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxLevelSum(self, root: Optional[TreeNode]) -> int:
        # level order traversal and keep track of max sum of level and the level
        maxsumlevel = 1
        maxsum = root.val
        q = [root]
        level = 1
        while len(q)!=0:
            newq = []
            currsum = 0
            for i in range(0,len(q)):
                curr = q[i]
                if curr.left:
                    newq.append(curr.left)
                if curr.right:
                    newq.append(curr.right)
                currsum+= curr.val
            q = newq
            if maxsum<currsum:
                maxsum = currsum
                maxsumlevel = level
            level+=1
        return maxsumlevel





        
