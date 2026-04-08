class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i,n in enumerate(nums):
            t = target-n
            if t in m:
                return [m[t],i]
            else:
                m[n]=i
        return [-1,-1]
            
                
        
