class Solution:
    def rob(self, nums: List[int]) -> int:
        @lru_cache(None)
        def solve(i):
            if(i>=len(nums)):
                return 0
            skip = solve(i+1)
            rob = nums[i]+solve(i+2)
            return max(skip,rob)
        return solve(0)
        
