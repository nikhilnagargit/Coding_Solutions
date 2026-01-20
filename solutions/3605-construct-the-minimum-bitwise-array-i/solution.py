class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        m = {}
        for i in range(0,1000):
            value = (i)|(i+1)
            if value in m :
                continue
            else:
                m[value]=i

        ans = []
        for i in nums:
            if i in m:
                ans.append(m[i])
            else:
                ans.append(-1)
        return ans
