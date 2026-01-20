class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = []
        for n in nums:
            if(n%2==0):
                ans.append(-1)
                continue
            mask = 1
            for i in range(0,32):
                if((mask & n)):
                    pass
                else:
                    mask = mask>>1
                    ans.append(n^mask)
                    break
                mask = mask<<1
        return ans
