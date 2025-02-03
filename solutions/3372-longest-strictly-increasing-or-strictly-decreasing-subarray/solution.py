class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        if len(nums)==0:
            return 0
        longest = 1
        prev = nums[0]
        l = 1
        t = 1
        for i in range(1,len(nums)):
            if(nums[i]>prev):
                l+=1
                t=1
            elif(nums[i]<prev):
                l=1
                t+=1
            else:
                l=1
                t=1
            longest = max(longest,l,t)
            prev = nums[i]


        return longest
        

