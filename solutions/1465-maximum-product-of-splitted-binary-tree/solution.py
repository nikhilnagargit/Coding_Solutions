# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.maxP = -float("inf")
        self.MOD = 1000000007

    def findSum(self,root:Optional[TreeNode]):
        if not root:
            return 0
        sumi = root.val
        sumi+= self.findSum(root.left)
        sumi+= self.findSum(root.right)
        return sumi
    
    def solve(self,totalSum,root):
        if not root:
            return 0
        # current level sum
        sumi = root.val
        sumi+= self.solve(totalSum,root.left)
        sumi+= self.solve(totalSum,root.right)
        # broken edge remaining tree sum
        remainingSum = totalSum-sumi
        # maxproduct
        self.maxP = max(self.maxP, (remainingSum*sumi))
        return sumi
            
    def maxProduct(self, root: Optional[TreeNode]) -> int:
        # find the sum of the tree.
        totalSum = self.findSum(root)
        # perform comparision for each possible sum
        self.solve(totalSum,root)
        return self.maxP%self.MOD
        
