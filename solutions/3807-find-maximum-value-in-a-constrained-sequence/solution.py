class Solution:
    def findMaxVal(self, n: int, restrictions: List[List[int]], diff: List[int]) -> int:
        maxLimits = [float("inf")]*n
        # apply restrictions first
        for r in restrictions:
            maxLimits[r[0]]=r[1]
        #spread the limit for each index according to diff
        for i in range(n-2,-1,-1):
            maxLimits[i] = min(maxLimits[i],maxLimits[i+1]+diff[i])
        # form the new array
        arr = [0]*n

        for i in range(1,n):
            arr[i] = min(maxLimits[i], arr[i-1]+diff[i-1])

        return max(arr)
        

