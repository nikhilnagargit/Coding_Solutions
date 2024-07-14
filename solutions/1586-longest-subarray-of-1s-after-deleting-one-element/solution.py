class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        left = 0
        zeroCount = 0
        maxwindowsize = 0

        for i in range(0,len(nums)):
            zeroCount += (nums[i]==0)
            while(zeroCount>1):
                zeroCount -= (nums[left]==0)
                left+=1
            
            maxwindowsize= max(maxwindowsize,i-left)
        return maxwindowsize
            

        
