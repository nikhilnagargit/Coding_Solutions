class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        leftProduct = [0]*len(nums)
        rightProduct = [0]*len(nums)
    
        # left to right
        leftProduct[0] = nums[0]
        for i in range(1,len(nums)):
            leftProduct[i] = nums[i]*leftProduct[i-1]
        
        # print(leftProduct)
        # right to left
        rightProduct[-1] = nums[-1]
        for i in range(len(nums)-2,-1,-1):
            rightProduct[i] = nums[i]*rightProduct[i+1]

        # print(rightProduct)

        # right to left
        ans = [0 for i in range(len(nums))]
        ans[0] = rightProduct[1]
        ans[-1] = leftProduct[-2]

        for i in range(1,len(nums)-1):
            ans[i] = leftProduct[i-1]*rightProduct[i+1]

        return ans
        
