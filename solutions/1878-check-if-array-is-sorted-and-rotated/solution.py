class Solution:
    def check(self, nums: List[int]) -> bool:
        breakcount=0
        if len(nums)<=1:
            return True
        for i in range(1,len(nums)):
            if nums[i-1]>nums[i]:
                breakcount+=1
        if nums[0]<nums[-1]:
            breakcount+=1
        if breakcount>1:
            return False
        return True
        
